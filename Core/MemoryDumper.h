#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "DebugTypes.h"

class MemoryManager;
class BaseCartridge;
class Ppu;
enum class SnesMemoryType;

class MemoryDumper
{
private:
	shared_ptr<Ppu> _ppu;
	shared_ptr<MemoryManager> _memoryManager;
	shared_ptr<BaseCartridge> _cartridge;

public:
	MemoryDumper(shared_ptr<Ppu> ppu, shared_ptr<MemoryManager> memoryManager, shared_ptr<BaseCartridge> cartridge);

	uint32_t GetMemorySize(SnesMemoryType type);
	void GetMemoryState(SnesMemoryType type, uint8_t *buffer);

	uint8_t GetMemoryValue(SnesMemoryType memoryType, uint32_t address, bool disableSideEffects = true);
	void SetMemoryValue(SnesMemoryType memoryType, uint32_t address, uint8_t value, bool disableSideEffects = true);
	void SetMemoryValues(SnesMemoryType memoryType, uint32_t address, uint8_t* data, uint32_t length);
	void SetMemoryState(SnesMemoryType type, uint8_t *buffer, uint32_t length);
};