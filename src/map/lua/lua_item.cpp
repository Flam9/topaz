﻿/*
===========================================================================

Copyright (c) 2010-2015 Darkstar Dev Teams

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses/

===========================================================================
*/

#include "lua_item.h"

#include "../../common/showmsg.h"
#include "../items/item.h"
#include "../items/item_equipment.h"
#include "../items/item_general.h"
#include "../items/item_weapon.h"
#include "../utils/itemutils.h"

CLuaItem::CLuaItem(CItem* PItem)
{
    m_PLuaItem = PItem;
}

inline int32 CLuaItem::getID(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushinteger(L, m_PLuaItem->getID());
    return 1;
}

inline int32 CLuaItem::getSubID(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushinteger(L, m_PLuaItem->getSubID());
    return 1;
}

inline int32 CLuaItem::getFlag(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushinteger(L, m_PLuaItem->getFlag());
    return 1;
}

inline int32 CLuaItem::getAHCat(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushinteger(L, m_PLuaItem->getAHCat());
    return 1;
}

inline int32 CLuaItem::getQuantity(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushinteger(L, m_PLuaItem->getQuantity());
    return 1;
}

inline int32 CLuaItem::getBasePrice(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    uint32 basePrice = static_cast<CItem*>(m_PLuaItem)->getBasePrice();
    lua_pushinteger(L, basePrice);
    return 1;
}

inline int32 CLuaItem::getLocationID(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushinteger(L, m_PLuaItem->getLocationID());
    return 1;
}

inline int32 CLuaItem::getSlotID(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushinteger(L, m_PLuaItem->getSlotID());
    return 1;
}

inline int32 CLuaItem::getTrialNumber(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    uint16 trialID = static_cast<CItemEquipment*>(m_PLuaItem)->getTrialNumber();
    lua_pushinteger(L, trialID);
    return 1;
}

inline int32 CLuaItem::getWornItem(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushinteger(L, m_PLuaItem->m_extra[0]);
    return 1;
}

inline int32 CLuaItem::isType(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    TPZ_DEBUG_BREAK_IF(lua_isnil(L, 1) || !lua_isnumber(L, 1));

    auto type = (uint8)lua_tointeger(L, 1);

    lua_pushboolean(L, m_PLuaItem->isType((ITEM_TYPE)type));
    return 1;
}

inline int32 CLuaItem::isSubType(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    TPZ_DEBUG_BREAK_IF(lua_isnil(L, 1) || !lua_isnumber(L, 1));

    auto subtype = (uint8)lua_tointeger(L, 1);

    lua_pushboolean(L, m_PLuaItem->isSubType((ITEM_SUBTYPE)subtype));
    return 1;
}

inline int32 CLuaItem::getName(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    lua_pushstring(L, (const char*)m_PLuaItem->getName());
    return 1;
}

inline int32 CLuaItem::getILvl(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    uint16 ilvl = static_cast<CItemEquipment*>(m_PLuaItem)->getILvl();
    lua_pushinteger(L, ilvl);
    return 1;
}

inline int32 CLuaItem::getReqLvl(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    uint16 lvl = static_cast<CItemEquipment*>(m_PLuaItem)->getReqLvl();
    lua_pushinteger(L, lvl);
    return 1;
}

inline int32 CLuaItem::getMod(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    TPZ_DEBUG_BREAK_IF(lua_isnil(L, 1) || !lua_isnumber(L, 1));

    CItemEquipment* PItem = (CItemEquipment*)m_PLuaItem;

    Mod mod = static_cast<Mod>(lua_tointeger(L, 1));

    lua_pushinteger(L, PItem->getModifier(mod));
    return 1;
}

inline int32 CLuaItem::addMod(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    TPZ_DEBUG_BREAK_IF(lua_isnil(L, 1) || !lua_isnumber(L, 1));
    TPZ_DEBUG_BREAK_IF(lua_isnil(L, 2) || !lua_isnumber(L, 2));

    CItemEquipment* PItem = (CItemEquipment*)m_PLuaItem;

    // Checks if this item is just a pointer created by GetItem()
    // All item-modifying functions in this file should check this!
    if (itemutils::IsItemPointer(PItem))
    {
        return 0;
    }

    Mod  mod   = static_cast<Mod>(lua_tointeger(L, 1));
    auto power = (int16)lua_tointeger(L, 2);

    PItem->addModifier(CModifier(mod, power));
    return 0;
}

inline int32 CLuaItem::delMod(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    TPZ_DEBUG_BREAK_IF(lua_isnil(L, 1) || !lua_isnumber(L, 1));
    TPZ_DEBUG_BREAK_IF(lua_isnil(L, 2) || !lua_isnumber(L, 2));

    CItemEquipment* PItem = (CItemEquipment*)m_PLuaItem;

    Mod  mod   = static_cast<Mod>(lua_tointeger(L, 1));
    auto power = (int16)lua_tointeger(L, 2);

    PItem->addModifier(CModifier(mod, -power));
    return 0;
}

inline int32 CLuaItem::getAugment(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);
    TPZ_DEBUG_BREAK_IF(lua_isnil(L, 1) || !lua_isnumber(L, 1));

    CItemEquipment* PItem = (CItemEquipment*)m_PLuaItem;

    auto   slot       = (uint8)lua_tointeger(L, 1);
    uint16 augment    = PItem->getAugment(slot);
    uint16 augmentid  = (uint16)unpackBitsBE((uint8*)(&augment), 0, 11);
    uint8  augmentVal = (uint8)unpackBitsBE((uint8*)(&augment), 11, 5);

    lua_pushinteger(L, augmentid);
    lua_pushinteger(L, augmentVal);

    return 2;
}

inline int32 CLuaItem::getSkillType(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    auto* PItem = dynamic_cast<CItemWeapon*>(m_PLuaItem);

    if (PItem)
    {
        lua_pushinteger(L, PItem->getSkillType());
    }
    else
    {
        lua_pushinteger(L, -1);
    }

    return 1;
}

inline int32 CLuaItem::getWeaponskillPoints(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    auto* PItem = dynamic_cast<CItemWeapon*>(m_PLuaItem);

    if (PItem)
    {
        lua_pushinteger(L, PItem->getCurrentUnlockPoints());
    }
    else
    {
        lua_pushinteger(L, 0);
    }

    return 1;
}

inline int32 CLuaItem::isTwoHanded(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    if (CItemWeapon* PWeapon = dynamic_cast<CItemWeapon*>(m_PLuaItem))
    {
        lua_pushboolean(L, PWeapon->isTwoHanded());
    }
    else
    {
        ShowError(CL_RED "CLuaItem::isTwoHanded - not a valid Weapon.\n" CL_RESET);
        lua_pushboolean(L, 0);
    }

    return 1;
}

inline int32 CLuaItem::isHandToHand(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    if (CItemWeapon* PWeapon = dynamic_cast<CItemWeapon*>(m_PLuaItem))
    {
        lua_pushboolean(L, PWeapon->isHandToHand());
    }
    else
    {
        ShowError(CL_RED "CLuaItem::isHandToHand - not a valid Weapon.\n" CL_RESET);
        lua_pushboolean(L, 0);
    }

    return 1;
}

inline int32 CLuaItem::isShield(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    if (CItemEquipment* PArmor = dynamic_cast<CItemEquipment*>(m_PLuaItem))
    {
        lua_pushboolean(L, PArmor->IsShield());
    }
    else
    {
        ShowError(CL_RED "CLuaItem::isShield - not a valid Armor.\n" CL_RESET);
        lua_pushboolean(L, 0);
    }

    return 1;
}

inline int32 CLuaItem::getSignature(lua_State* L)
{
    TPZ_DEBUG_BREAK_IF(m_PLuaItem == nullptr);

    int8 signature[21];
    if (m_PLuaItem->isType(ITEM_LINKSHELL))
    {
        DecodeStringLinkshell((int8*)m_PLuaItem->getSignature(), signature);
    }
    else
    {
        DecodeStringSignature((int8*)m_PLuaItem->getSignature(), signature);
    }

    lua_pushstring(L, (const char*)signature);

    return 1;
}
//==========================================================//

void CLuaItem::Register(sol::state& lua)
{
    SOL_START(CItem, CLuaItem)
    SOL_REGISTER(getID)
    SOL_REGISTER(getSubID)
    SOL_REGISTER(getFlag)
    SOL_REGISTER(getAHCat)
    SOL_REGISTER(getQuantity)
    SOL_REGISTER(getLocationID)
    SOL_REGISTER(getBasePrice)
    SOL_REGISTER(getSlotID)
    SOL_REGISTER(getTrialNumber)
    SOL_REGISTER(getWornItem)
    SOL_REGISTER(isType)
    SOL_REGISTER(isSubType)
    SOL_REGISTER(getName)
    SOL_REGISTER(getILvl)
    SOL_REGISTER(getReqLvl)
    SOL_REGISTER(getMod)
    SOL_REGISTER(addMod)
    SOL_REGISTER(delMod)
    SOL_REGISTER(getAugment)
    SOL_REGISTER(getSkillType)
    SOL_REGISTER(getWeaponskillPoints)
    SOL_REGISTER(isTwoHanded)
    SOL_REGISTER(isHandToHand)
    SOL_REGISTER(isShield)
    SOL_REGISTER(getSignature)
    SOL_END()
};

//======================================================//
