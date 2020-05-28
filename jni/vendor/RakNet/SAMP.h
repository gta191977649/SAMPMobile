#pragma once

//System Includes
#include <stdint.h>
#include <stdio.h>

//RakNet Stuff
#include "StringCompressor.h"
#include "NetworkTypes.h"
#include "PacketEnumerations.h"
#include "BitStream.h"
#include "RakNetworkFactory.h"
#include "RakClientInterface.h"

//GPCI
#define NETGAME_GPCIHASH "FF2BE5E6F5D9392F57C4E66F7AD78767277C6E4F6B"
#define NETGAME_COOKIE 0x6969
#define NETGAME_VERSION 0x0FD9
#define CLIENT_VERSION "0.3.7"

//SAMP RPCs
#define RPC_ClickPlayer "\x17"
#define RPC_ClientJoin "\x19"
#define RPC_EnterVehicle "\x1A"
#define RPC_EnterEditObject "\x1B"
#define RPC_SetTimeEx "\x1D"
#define RPC_ToggleClock "\x1E"
#define RPC_WorldPlayerAdd "\x20"
#define RPC_Show3DText "\x24"
#define RPC_DisableCheckpoint "\x25"
#define RPC_SetRaceCheckpoint "\x26"
#define RPC_DisableRaceCheckpoint "\x27"
#define RPC_GameModeRestart "\x28"
#define RPC_PlayAudioStream "\x29"
#define RPC_StopAudioStream "\x2A"
#define RPC_ServerCommand "\x32"
#define RPC_Spawn "\x34"
#define RPC_Death "\x35"
#define RPC_NPCJoin "\x36"
#define RPC_Destroy3DText "\x3A"
#define RPC_PlayerUpdate "\x3C"
#define RPC_ShowDialog "\x3D"
#define RPC_DialogResponse "\x3E"
#define RPC_DestroyPickup "\x3F"
#define RPC_ClientMessage "\x5D"
#define RPC_WorldTime "\x5E"
#define RPC_Pickup "\x5F"
#define RPC_ScmEvent "\x60"
#define RPC_DestroyWeaponPickup "\x61"
#define RPC_Chat "\x65"
#define RPC_SvrStats "\x66"
#define RPC_DamageVehicle "\x6A"
#define RPC_SetCheckpoint "\x6B"
#define RPC_PlayerGiveTakeDamage "\x73"
#define RPC_EditObject "\x75"
#define RPC_SetInteriorId "\x76"
#define RPC_MapMarker "\x77"
#define RPC_RequestClass "\x80"
#define RPC_RequestSpawn "\x81"
#define RPC_ConnectionRejected "\x82"
#define RPC_PickedUpPickup "\x83"
#define RPC_MenuSelect "\x84"
#define RPC_VehicleDestroyed "\x88"
#define RPC_ServerJoin "\x89"
#define RPC_ServerQuit "\x8A"
#define RPC_InitGame "\x8B"
#define RPC_MenuQuit "\x8C"
#define RPC_Weather "\x98"
#define RPC_ExitVehicle "\x9A"
#define RPC_UpdateScoresPingsIPs "\x9B"
#define RPC_WorldPlayerRemove "\xA3"
#define RPC_WorldVehicleAdd "\xA4"
#define RPC_WorldVehicleRemove "\xA5"
#define RPC_WorldPlayerDeath "\xA6"
#define RPC_WorldActorAdd "\xAB"
#define RPC_WorldActorRemove "\xAC"

#define RPC_ScrSetPlayerName "\x0B"
#define RPC_ScrSetPlayerPos "\x0C"
#define RPC_ScrSetPlayerPosFindZ "\x0D"
#define RPC_ScrSetPlayerHealth "\x0E"
#define RPC_ScrTogglePlayerControllable "\x0F"
#define RPC_ScrPlaySound "\x10"
#define RPC_ScrSetWorldBounds "\x11"
#define RPC_ScrHaveSomeMoney "\x12"
#define RPC_ScrSetPlayerFacingAngle "\x13"
#define RPC_ScrResetMoney "\x14"
#define RPC_ScrResetPlayerWeapons "\x15"
#define RPC_ScrGivePlayerWeapon "\x16"
#define RPC_ScrVehicleParamsEx "\x18"
#define RPC_ScrSetPlayerDrunkLevel "\x23"
#define RPC_ScrRemoveBuildingForPlayer "\x2B"
#define RPC_ScrCreateObject "\x2C"
#define RPC_ScrSetObjectPos "\x2D"
#define RPC_ScrSetObjectRotation "\x2E"
#define RPC_ScrDestroyObject "\x2F"
#define RPC_ScrDeathMessage "\x37"
#define RPC_ScrSetMapIcon "\x38"
#define RPC_ScrRemoveComponent "\x39"
#define RPC_ScrLinkVehicle "\x41"
#define RPC_ScrSetPlayerArmour "\x42"
#define RPC_ScrSetArmedWeapon "\x43"
#define RPC_ScrSetSpawnInfo "\x44"
#define RPC_ScrSetPlayerTeam "\x45"
#define RPC_ScrPutPlayerInVehicle "\x46"
#define RPC_ScrRemovePlayerFromVehicle "\x47"
#define RPC_ScrSetPlayerColor "\x48"
#define RPC_ScrDisplayGameText "\x49"
#define RPC_ScrForceSpawnSelection "\x4A"
#define RPC_ScrAttachObjectToPlayer "\x4B"
#define RPC_ScrInitMenu "\x4C"
#define RPC_ScrShowMenu "\x4D"
#define RPC_ScrHideMenu "\x4E"
#define RPC_ScrCreateExplosion "\x4F"
#define RPC_ScrShowNameTag "\x50"
#define RPC_ScrInterpolateCamera "\x52"
#define RPC_ScrTextDrawSelection "\x53"
#define RPC_ScrSetObjectMaterial "\x54"
#define RPC_ScrStopFlashGangZone "\x55"
#define RPC_ScrApplyAnimation "\x56"
#define RPC_ScrClearAnimations "\x57"
#define RPC_ScrSetSpecialAction "\x58"
#define RPC_ScrSetFightingStyle "\x59"
#define RPC_ScrSetPlayerVelocity "\x5A"
#define RPC_ScrSetVehicleVelocity "\x5B"
#define RPC_ScrSetPlayerDrunkVisuals "\x5C"
#define RPC_ScrSetVehicleTireStatus "\x62"
#define RPC_ScrMoveObject "\x63"
#define RPC_ScrEnableStuntBonus "\x68"
#define RPC_ScrEditTextDraw "\x69"
#define RPC_ScrAddGangZone "\x6C"
#define RPC_ScrSetPlayerAttachedObject "\x71"
#define RPC_ScrRemoveGangZone "\x78"
#define RPC_ScrFlashGangZone "\x79"
#define RPC_ScrStopObject "\x7A"
#define RPC_ScrNumberPlate "\x7B"
#define RPC_ScrTogglePlayerSpectating "\x7C"
#define RPC_ScrSetPlayerSpectating "\x7D"
#define RPC_ScrPlayerSpectatePlayer "\x7E"
#define RPC_ScrPlayerSpectateVehicle "\x7F"
#define RPC_ScrSetPlayerWantedLevel "\x85"
#define RPC_ScrShowTextDraw "\x86"
#define RPC_ScrHideTextDraw "\x87"
#define RPC_ScrDisableMapIcon "\x90"
#define RPC_ScrSetWeaponAmmo "\x91"
#define RPC_ScrSetGravity "\x92"
#define RPC_ScrSetVehicleHealth "\x93"
#define RPC_ScrAttachTrailerToVehicle "\x94"
#define RPC_ScrDetachTrailerFromVehicle "\x95"
#define RPC_ScrSetPlayerDrunkHandling "\x96"
#define RPC_ScrSetPlayerSkin "\x99"
#define RPC_ScrSetInterior "\x9C"
#define RPC_ScrSetCameraPos "\x9D"
#define RPC_ScrSetCameraLookAt "\x9E"
#define RPC_ScrSetVehiclePos "\x9F"
#define RPC_ScrSetVehicleZAngle "\xA0"
#define RPC_ScrVehicleParams "\xA1"
#define RPC_ScrSetCameraBehindPlayer "\xA2"
#define RPC_ScrApplyActorAnimation "\xAD"
#define RPC_ScrClearActorAnimations "\xAE"
#define RPC_ScrSetActorFacingAngle "\xAF"
#define RPC_ScrSetActorPos "\xB0"
#define RPC_ScrSetActorHealth "\xB1"
#define RPC_ScrChatBubble "\x3B"
#define RPC_ScrSetTargeting "\xAA"