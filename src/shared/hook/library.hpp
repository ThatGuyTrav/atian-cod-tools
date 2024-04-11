#pragma once
#include <detours.h>
#include "../process.hpp"
#include "../utils.hpp"

namespace hook::library {
	/*
	 * @return module from an address
	 */
	HMODULE GetLibraryInfo(const void* address);

	/*
	 * Get the name of a library
	 * @param hmod module
	 * @return name without the path
	 */
	const char* GetLibraryName(HMODULE hmod);

	/*
	 * Get the path of a library
	 * @param hmod module
	 * @return path
	 */
	const char* GetLibraryPath(HMODULE hmod);

	/*
	 * Locate the PDB of a module
	 * @return pdb path or null
	 */
	const char* LocatePDB(HMODULE hmod);

	class Library {
		HMODULE hmod{};
	public:
		Library() : hmod(process::BaseHandle()) {
		}

		Library(HMODULE hmod) : hmod(hmod) {
		}

		Library(const char* name) : hmod(process::LoadLib(name)) {
		}

		Library(const std::string& name, bool system = false) : hmod(system ? process::LoadSysLib(name) : process::LoadLib(name)) {
		}

		Library(const Library& other) : hmod(other.hmod) {
		}

		constexpr bool operator==(const Library& other) const {
			return hmod == other.hmod;
		}

		constexpr operator bool() const {
			return hmod != 0;
		}

		constexpr void* operator*() const {
			return hmod;
		}

		inline void* operator[](size_t offset) const {
			return reinterpret_cast<byte*>(hmod) + offset;
		}

		inline void* operator[](const char* name) const {
			return GetProcAddress(hmod, name);
		}

		inline const char* GetName() const {
			return GetLibraryName(hmod);
		}

		inline const char* GetPath() const {
			return GetLibraryPath(hmod);
		}

		inline const char* GetPDB() const {
			return LocatePDB(hmod);
		}

		inline PIMAGE_NT_HEADERS GetNTHeader() const {
			return process::PImageNtHeader(hmod);
		}

		inline PIMAGE_OPTIONAL_HEADER GetOptHeader() const {
			return process::PImageOptHeader(hmod);
		}

		inline PIMAGE_DOS_HEADER GetDosHeader() const {
			return process::PImageDosHeader(hmod);
		}
	};

	/*
	 * Detour structure
	 */
	class Detour {
		void* origin{};
		void* base{};
	public:
		inline Detour() {}

		/*
		 * Create a detour from a base to a location
		 * @param base origin
		 * @param to destination
		 */
		void Create(void* base, void* to) {
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());

			this->base = origin = base;

			DetourAttach(&(PVOID&)this->base, to);

			LONG error = DetourTransactionCommit();

			if (error != NO_ERROR) {
				throw std::runtime_error(utils::va("Can't commit detour %p -> %p", base, to));
			}
		}

		constexpr operator bool() const {
			return base;
		}

		/*
		 * @return origin pointer
		 */
		constexpr void* GetOrigin() const {
			return origin;
		}

		/*
		 * @return base pointer
		 */
		template<typename Type>
		constexpr Type* GetBase() const {
			return reinterpret_cast<Type*>(base);
		}

		/*
		 * call the base pointer
		 */
		template<typename Out = void, typename... Args>
		inline Out Call(Args ... args) const {
			return reinterpret_cast<Out(*)(Args ...)>(base)(args...);
		}

	};
}