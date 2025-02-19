#pragma once

#include "util/types.hpp"

#include <string>
#include <vector>
#include <memory>

enum SELF_KEY_TYPE
{
	KEY_LV0 = 1,
	KEY_LV1,
	KEY_LV2,
	KEY_APP,
	KEY_ISO,
	KEY_LDR,
	KEY_UNK7,
	KEY_NPDRM
};

struct SELF_KEY
{
	u64 version_start{};
	u64 version_end{};
	u16 revision{};
	u32 self_type{};
	u8 erk[0x20]{};
	u8 riv[0x10]{};
	u8 pub[0x28]{};
	u8 priv[0x15]{};
	u32 curve_type{};

	SELF_KEY(u64 ver_start, u64 ver_end, u16 rev, u32 type, const std::string& e, const std::string& r, const std::string& pb, const std::string& pr, u32 ct);
};

constexpr u32 PASSPHRASE_KEY_LEN = 16;
constexpr u32 PASSPHRASE_OUT_LEN = 4096;

constexpr u8 SC_ISO_SERIES_KEY_1[PASSPHRASE_KEY_LEN] = {
	0xD4, 0x13, 0xB8, 0x96, 0x63, 0xE1, 0xFE, 0x9F, 0x75, 0x14, 0x3D, 0x3B, 0xB4, 0x56, 0x52, 0x74 // D413B89663E1FE9F75143D3BB4565274
};

constexpr u8 SC_ISO_SERIES_KEY_2[PASSPHRASE_KEY_LEN] = {
	0xFA, 0x72, 0xCE, 0xEF, 0x59, 0xB4, 0xD2, 0x98, 0x9F, 0x11, 0x19, 0x13, 0x28, 0x7F, 0x51, 0xC7 // FA72CEEF59B4D2989F111913287F51C7
};

constexpr u8 SC_KEY_FOR_MASTER_1[PASSPHRASE_KEY_LEN] = {
	0xDA, 0xA4, 0xB9, 0xF2, 0xBC, 0x70, 0xB2, 0x80, 0xA7, 0xB3, 0x40, 0xFA, 0x0D, 0x04, 0xBA, 0x14 // DAA4B9F2BC70B280A7B340FA0D04BA14
};

constexpr u8 SC_KEY_FOR_MASTER_2[PASSPHRASE_KEY_LEN] = {
	0x29, 0xC1, 0x94, 0xFF, 0xEC, 0x1F, 0xD1, 0x4D, 0x4A, 0xAE, 0x00, 0x6C, 0x32, 0xB3, 0x59, 0x90 // 29C194FFEC1FD14D4AAE006C32B35990
};

constexpr u8 SC_ISO_SERIES_INTERNAL_KEY_1[PASSPHRASE_KEY_LEN] = {
	0x73, 0x63, 0x6B, 0x65, 0x79, 0x5F, 0x73, 0x65, 0x72, 0x69, 0x65, 0x73, 0x6B, 0x65, 0x79, 0x00 // 73636B65795F7365726965736B657900
};

constexpr u8 SC_ISO_SERIES_INTERNAL_KEY_2[PASSPHRASE_KEY_LEN] = {
	0x73, 0x63, 0x6B, 0x65, 0x79, 0x5F, 0x73, 0x65, 0x72, 0x69, 0x65, 0x73, 0x6B, 0x65, 0x79, 0x32 // 73636B65795F7365726965736B657932
};

constexpr u8 SC_ISO_SERIES_INTERNAL_KEY_3[PASSPHRASE_KEY_LEN] = {
	0x73, 0x63, 0x6B, 0x65, 0x79, 0x5F, 0x66, 0x6F, 0x72, 0x5F, 0x6D, 0x61, 0x73, 0x74, 0x65, 0x72 // 73636B65795F666F725F6D6173746572
};

constexpr u8 PKG_AES_KEY_IDU[0x10] = {
	0x5d, 0xb9, 0x11, 0xe6, 0xb7, 0xe5, 0x0a, 0x7d, 0x32, 0x15, 0x38, 0xfd, 0x7c, 0x66, 0xf1, 0x7b
};

constexpr u8 PKG_AES_KEY[0x10] = {
	0x2e, 0x7b, 0x71, 0xd7, 0xc9, 0xc9, 0xa1, 0x4e, 0xa3, 0x22, 0x1f, 0x18, 0x88, 0x28, 0xb8, 0xf8
};

constexpr u8 PKG_AES_KEY2[0x10] = {
	0x07, 0xf2, 0xc6, 0x82, 0x90, 0xb5, 0x0d, 0x2c, 0x33, 0x81, 0x8d, 0x70, 0x9b, 0x60, 0xe6, 0x2b
};

constexpr u8 PKG_AES_KEY_VITA_1[0x10] = {
	0xE3, 0x1A, 0x70, 0xC9, 0xCE, 0x1D, 0xD7, 0x2B, 0xF3, 0xC0, 0x62, 0x29, 0x63, 0xF2, 0xEC, 0xCB
};

constexpr u8 PKG_AES_KEY_VITA_2[0x10] = {
	0x42, 0x3A, 0xCA, 0x3A, 0x2B, 0xD5, 0x64, 0x9F, 0x96, 0x86, 0xAB, 0xAD, 0x6F, 0xD8, 0x80, 0x1F
};

constexpr u8 PKG_AES_KEY_VITA_3[0x10] = {
	0xAF, 0x07, 0xFD, 0x59, 0x65, 0x25, 0x27, 0xBA, 0xF1, 0x33, 0x89, 0x66, 0x8B, 0x17, 0xD9, 0xEA
};

constexpr u8 NP_IDPS[0x10] = {
	0x5E, 0x06, 0xE0, 0x4F, 0xD9, 0x4A, 0x71, 0xBF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
};

constexpr u8 NP_KLIC_FREE[0x10] = {
	0x72, 0xF9, 0x90, 0x78, 0x8F, 0x9C, 0xFF, 0x74, 0x57, 0x25, 0xF0, 0x8E, 0x4C, 0x12, 0x83, 0x87
};

constexpr u8 NP_OMAC_KEY_2[0x10] = {
	0x6B, 0xA5, 0x29, 0x76, 0xEF, 0xDA, 0x16, 0xEF, 0x3C, 0x33, 0x9F, 0xB2, 0x97, 0x1E, 0x25, 0x6B
};

constexpr u8 NP_OMAC_KEY_3[0x10] = {
	0x9B, 0x51, 0x5F, 0xEA, 0xCF, 0x75, 0x06, 0x49, 0x81, 0xAA, 0x60, 0x4D, 0x91, 0xA5, 0x4E, 0x97
};

constexpr u8 NP_KLIC_KEY[0x10] = {
	0xF2, 0xFB, 0xCA, 0x7A, 0x75, 0xB0, 0x4E, 0xDC, 0x13, 0x90, 0x63, 0x8C, 0xCD, 0xFD, 0xD1, 0xEE
};

constexpr u8 NP_RIF_KEY[0x10] = {
	0xDA, 0x7D, 0x4B, 0x5E, 0x49, 0x9A, 0x4F, 0x53, 0xB1, 0xC1, 0xA1, 0x4A, 0x74, 0x84, 0x44, 0x3B
};

// PSP Minis
constexpr u8 NP_PSP_KEY_1[0x10] = {
	0x2A, 0x6A, 0xFB, 0xCF, 0x43, 0xD1, 0x57, 0x9F, 0x7D, 0x73, 0x87, 0x41, 0xA1, 0x3B, 0xD4, 0x2E
};

// PSP Remasters
constexpr u8 NP_PSP_KEY_2[0x10] = {
	0x0D, 0xB8, 0x57, 0x32, 0x36, 0x6C, 0xD7, 0x34, 0xFC, 0x87, 0x9E, 0x74, 0x33, 0x43, 0xBB, 0x4F
};

constexpr u8 NP_PSX_KEY[0x10] = {
	0x52, 0xC0, 0xB5, 0xCA, 0x76, 0xD6, 0x13, 0x4B, 0xB4, 0x5F, 0xC6, 0x6C, 0xA6, 0x37, 0xF2, 0xC1
};

constexpr u8 RAP_KEY[0x10] = {
	0x86, 0x9F, 0x77, 0x45, 0xC1, 0x3F, 0xD8, 0x90, 0xCC, 0xF2, 0x91, 0x88, 0xE3, 0xCC, 0x3E, 0xDF
};

constexpr u8 RAP_PBOX[0x10] = {
	0x0C, 0x03, 0x06, 0x04, 0x01, 0x0B, 0x0F, 0x08, 0x02, 0x07, 0x00, 0x05, 0x0A, 0x0E, 0x0D, 0x09
};

constexpr u8 RAP_E1[0x10] = {
	0xA9, 0x3E, 0x1F, 0xD6, 0x7C, 0x55, 0xA3, 0x29, 0xB7, 0x5F, 0xDD, 0xA6, 0x2A, 0x95, 0xC7, 0xA5
};

constexpr u8 RAP_E2[0x10] = {
	0x67, 0xD4, 0x5D, 0xA3, 0x29, 0x6D, 0x00, 0x6A, 0x4E, 0x7C, 0x53, 0x7B, 0xF5, 0x53, 0x8C, 0x74
};

constexpr u8 SDAT_KEY[0x10] = {
	0x0D, 0x65, 0x5E, 0xF8, 0xE6, 0x74, 0xA9, 0x8A, 0xB8, 0x50, 0x5C, 0xFA, 0x7D, 0x01, 0x29, 0x33
};

constexpr u8 EDAT_KEY_0[0x10] = {
	0xBE, 0x95, 0x9C, 0xA8, 0x30, 0x8D, 0xEF, 0xA2, 0xE5, 0xE1, 0x80, 0xC6, 0x37, 0x12, 0xA9, 0xAE
};

constexpr u8 EDAT_HASH_0[0x10] = {
	0xEF, 0xFE, 0x5B, 0xD1, 0x65, 0x2E, 0xEB, 0xC1, 0x19, 0x18, 0xCF, 0x7C, 0x04, 0xD4, 0xF0, 0x11
};

constexpr u8 EDAT_KEY_1[0x10] = {
	0x4C, 0xA9, 0xC1, 0x4B, 0x01, 0xC9, 0x53, 0x09, 0x96, 0x9B, 0xEC, 0x68, 0xAA, 0x0B, 0xC0, 0x81
};

constexpr u8 EDAT_HASH_1[0x10] = {
	0x3D, 0x92, 0x69, 0x9B, 0x70, 0x5B, 0x07, 0x38, 0x54, 0xD8, 0xFC, 0xC6, 0xC7, 0x67, 0x27, 0x47
};

constexpr u8 EDAT_IV[0x10] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

constexpr u8 VSH_CURVE_P[0x14] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

constexpr u8 VSH_CURVE_A[0x14] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC
};

constexpr u8 VSH_CURVE_B[0x14] = {
	0xA6, 0x8B, 0xED, 0xC3, 0x34, 0x18, 0x02, 0x9C, 0x1D, 0x3C, 0xE3, 0x3B, 0x9A, 0x32, 0x1F, 0xCC, 0xBB, 0x9E, 0x0F, 0x0B
};

constexpr u8 VSH_CURVE_N[0x15] = {
	0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xB5, 0xAE, 0x3C, 0x52, 0x3E, 0x63, 0x94, 0x4F, 0x21, 0x27
};

constexpr u8 VSH_CURVE_GX[0x14] = {
	0x12, 0x8E, 0xC4, 0x25, 0x64, 0x87, 0xFD, 0x8F, 0xDF, 0x64, 0xE2, 0x43, 0x7B, 0xC0, 0xA1, 0xF6, 0xD5, 0xAF, 0xDE, 0x2C
};

constexpr u8 VSH_CURVE_GY[0x14] = {
	0x59, 0x58, 0x55, 0x7E, 0xB1, 0xDB, 0x00, 0x12, 0x60, 0x42, 0x55, 0x24, 0xDB, 0xC3, 0x79, 0xD5, 0xAC, 0x5F, 0x4A, 0xDF
};

constexpr u8 VSH_PUB[0x28] = {
	0x62, 0x27, 0xB0, 0x0A, 0x02, 0x85, 0x6F, 0xB0, 0x41, 0x08, 0x87, 0x67, 0x19, 0xE0, 0xA0, 0x18, 0x32, 0x91, 0xEE, 0xB9,
	0x6E, 0x73, 0x6A, 0xBF, 0x81, 0xF7, 0x0E, 0xE9, 0x16, 0x1B, 0x0D, 0xDE, 0xB0, 0x26, 0x76, 0x1A, 0xFF, 0x7B, 0xC8, 0x5B
};

constexpr u8 SCEPKG_RIV[0x10] = {
	0x4A, 0xCE, 0xF0, 0x12, 0x24, 0xFB, 0xEE, 0xDF, 0x82, 0x45, 0xF8, 0xFF, 0x10, 0x21, 0x1E, 0x6E
};

constexpr u8 SCEPKG_ERK[0x20] = {
	0xA9, 0x78, 0x18, 0xBD, 0x19, 0x3A, 0x67, 0xA1, 0x6F, 0xE8, 0x3A, 0x85, 0x5E, 0x1B, 0xE9, 0xFB, 0x56, 0x40, 0x93, 0x8D,
	0x4D, 0xBC, 0xB2, 0xCB, 0x52, 0xC5, 0xA2, 0xF8, 0xB0, 0x2B, 0x10, 0x31
};

constexpr u8 PUP_KEY[0x40] = {
	0xF4, 0x91, 0xAD, 0x94, 0xC6, 0x81, 0x10, 0x96, 0x91, 0x5F, 0xD5, 0xD2, 0x44, 0x81, 0xAE, 0xDC, 0xED, 0xED, 0xBE, 0x6B,
	0xE5, 0x13, 0x72, 0x4D, 0xD8, 0xF7, 0xB6, 0x91, 0xE8, 0x8A, 0x38, 0xF4, 0xB5, 0x16, 0x2B, 0xFB, 0xEC, 0xBE, 0x3A, 0x62,
	0x18, 0x5D, 0xD7, 0xC9, 0x4D, 0xA2, 0x22, 0x5A, 0xDA, 0x3F, 0xBF, 0xCE, 0x55, 0x5B, 0x9E, 0xA9, 0x64, 0x98, 0x29, 0xEB,
	0x30, 0xCE, 0x83, 0x66
};

                                             // name; location; notes
constexpr s64 PAID_01 = 0x0003CD28CB47D3C1L; // spu_token_processor.self; CoreOS; Only for 2E - 083.007
constexpr s64 PAID_02 = 0x1010000001000001L; // vsh / games / utilities; /dev_flash/, cell_root/target/images; only for 2E - 080.006
constexpr s64 PAID_03 = 0x1010000001000003L; // retail games and their updates
constexpr s64 PAID_04 = 0x1010000002000003L;
constexpr s64 PAID_05 = 0x1020000401000001L; // ps2emu; /dev_flash/ps2emu; CEX DEX DECR ?
constexpr s64 PAID_06 = 0x1050000003000001L; // lv2_kernel.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_07 = 0x1070000001000002L; // onicore_child.self; /dev_flash/vsh/module; same for CEX DEX DECR
constexpr s64 PAID_08 = 0x1070000002000002L; // mcore.self; /dev_flash/vsh/module; same for CEX DEX DECR
constexpr s64 PAID_09 = 0x1070000003000002L; // mgvideo.self; /dev_flash/vsh/module; same for CEX DEX DECR
constexpr s64 PAID_10 = 0x1070000004000002L; // swagner / swreset; /dev_flash/vsh/module; DTCP-IP DRM modules
constexpr s64 PAID_11 = 0x107000000E000001L; // vtrm_server.fself; lv1
constexpr s64 PAID_12 = 0x107000000F000001L; // update_manager_server.fself; lv1
constexpr s64 PAID_13 = 0x1070000010000001L; // sc_manager_server.fself; lv1
constexpr s64 PAID_14 = 0x1070000011000001L; // secure_rtc_server.fself; lv1
constexpr s64 PAID_15 = 0x1070000012000001L; // spm_server.fself; lv1
constexpr s64 PAID_16 = 0x1070000013000001L; // sb_manager_server.fself; lv1
constexpr s64 PAID_17 = 0x1070000014000001L; // framework.fself; lv1
constexpr s64 PAID_18 = 0x1070000015000001L; // lv2_loader.fself; lv1
constexpr s64 PAID_19 = 0x1070000016000001L; // profile_loader.fself; lv1
constexpr s64 PAID_20 = 0x1070000017000001L; // ss_init.fself; lv1
constexpr s64 PAID_21 = 0x1070000018000001L; // individual_info_mgr_server.fself; lv1
constexpr s64 PAID_22 = 0x1070000019000001L; // app_info_manager_server.fself; lv1
constexpr s64 PAID_23 = 0x107000001A000001L; // ss_sc_init_pu.fself; JIG lv1 proc
constexpr s64 PAID_24 = 0x107000001C000001L; // updater_frontend.fself; lv1
constexpr s64 PAID_25 = 0x107000001D000001L; // sysmgr_ss.fself; lv1
constexpr s64 PAID_26 = 0x107000001F000001L; // sb_iso_spu_module.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_27 = 0x1070000020000001L; // sc_iso.self / sc_iso_factory.self; CoreOS / [2.43 JIG PUP]; same for CEX DEX DECR
constexpr s64 PAID_28 = 0x1070000021000001L; // spp_verifier.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_29 = 0x1070000022000001L; // spu_pkg_rvk_verifier.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_30 = 0x1070000023000001L; // spu_token_processor.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_31 = 0x1070000024000001L; // sv_iso_spu_module.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_32 = 0x1070000025000001L; // aim_spu_module.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_33 = 0x1070000026000001L; // ss_sc_init.self; [2.43 JIG PUP]
constexpr s64 PAID_34 = 0x1070000027000001L; // dispatcher.fself; lv1;
constexpr s64 PAID_35 = 0x1070000028000001L; // factory_data_mngr_server.fself; JIG lv1 proc
constexpr s64 PAID_36 = 0x1070000029000001L; // fdm_spu_module.self; [2.43 JIG PUP]
constexpr s64 PAID_37 = 0x107000002A000001L;
constexpr s64 PAID_38 = 0x1070000031000001L;
constexpr s64 PAID_39 = 0x1070000032000001L; // ss_server1.fself; lv1
constexpr s64 PAID_40 = 0x1070000033000001L; // ss_server2.fself; lv1
constexpr s64 PAID_41 = 0x1070000034000001L; // ss_server3.fself; lv1
constexpr s64 PAID_42 = 0x1070000037000001L; // mc_iso_spu_module.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_43 = 0x1070000039000001L; // bdp_bdmv.self; /dev_flash/bdplayer
constexpr s64 PAID_44 = 0x107000003A000001L; // bdj.self; /dev_flash/bdplayer
constexpr s64 PAID_45 = 0x1070000040000001L; // sys/external modules; /dev_flash/sys/external; same for CEX DEX DECR (incl. liblv2dbg_for_cex.sprx + liblv2dbg_for_dex.sprx)
constexpr s64 PAID_46 = 0x1070000041000001L; // ps1emu; /dev_flash/ps1emu; CEX DEX DECR ?
constexpr s64 PAID_47 = 0x1070000043000001L; // me_iso_spu_module.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_48 = 0x1070000044000001L; // (related to usb dongle)
constexpr s64 PAID_49 = 0x1070000045000001L; // USB Dongle Authenticator; ss_server1.fself; same for CEX DEX DECR
constexpr s64 PAID_50 = 0x1070000046000001L; // spu_mode_auth.self; [2.43 JIG PUP]
constexpr s64 PAID_51 = 0x1070000047000001L; // otheros.self; otheros.self
constexpr s64 PAID_52 = 0x1070000048000001L; // ftpd; cell_root/target/images; DECR
constexpr s64 PAID_53 = 0x107000004C000001L; // spu_utoken_processor.self; CoreOS (since FW 2.40)
constexpr s64 PAID_54 = 0x107000004E000001L; // (syscall 878)
constexpr s64 PAID_55 = 0x107000004F000001L;
constexpr s64 PAID_56 = 0x1070000050000001L;
constexpr s64 PAID_57 = 0x1070000051000001L;
constexpr s64 PAID_58 = 0x1070000052000001L; // sys/internal CEX + vsh/module modules CEX; /dev_flash/sys/internal + /dev_flash/vsh/module; Differs between CEX (this authid) and DECR
constexpr s64 PAID_59 = 0x1070000054000001L; // (syscall 21)
constexpr s64 PAID_60 = 0x1070000055000001L; // manu_info_spu_module.self; CoreOS (since FW 3.50)
constexpr s64 PAID_61 = 0x1070000058000001L; // me_iso_for_ps2emu.self; CoreOS (since FW 3.70)
constexpr s64 PAID_62 = 0x1070000059000001L; // sv_iso_for_ps2emu.self; CoreOS (since FW 3.70)
constexpr s64 PAID_63 = 0x1070000300000001L; // Lv2diag.self; BD-remarry toolkit
constexpr s64 PAID_64 = 0x10700003FC000001L; // emer_init.self; CoreOS (since FW 2.00)
constexpr s64 PAID_65 = 0x10700003FD000001L; // ps3swu; PUP root; same for CEX DEX DECR
constexpr s64 PAID_66 = 0x10700003FD000001L; // PS3ToolUpdater; cell_root/target/images; Only DECR
constexpr s64 PAID_67 = 0x10700003FD000001L; // manufacturing_updater_for_reset.self; BD-remarry toolkit
constexpr s64 PAID_68 = 0x10700003FE000001L; // sys_agent.self DECR; /dev_flash/sys/internal; DECR
constexpr s64 PAID_69 = 0x10700003FF000001L; // db_backup, mkfs, mkfs_085, mount_hdd, registry_backup, set_monitor, most sys/internal modules DECR + most vsh/module modules DECR; /dev_flash/sys/internal + /dev_flash/vsh/module + cell_root/target/images; Differs between DECR (this authid) and CEX
constexpr s64 PAID_70 = 0x1070000400000001L; // vsh / games / utilities; /dev_flash/, cell_root/target/images; only for 081.003 - 083.007
constexpr s64 PAID_71 = 0x1070000409000001L; // psp_emulator.self; /dev_flash/pspemu/psp_emulator.self; CEX DEX DECR ?
constexpr s64 PAID_72 = 0x107000040A000001L; // psp_translator.self; /dev_flash/pspemu/psp_translator.self; CEX DEX DECR ?
constexpr s64 PAID_73 = 0x107000040B000001L; // emulator_api.sprx and other .sprx; /dev_flash/pspemu/release/; CEX DEX DECR ?
constexpr s64 PAID_74 = 0x107000040C000001L; // emulator_drm.sprx; /dev_flash/pspemu/release/emulator_drm.sprx; CEX DEX DECR ?
constexpr s64 PAID_75 = 0x107000040C000001L; // libchnnlsv.sprx; /dev_flash/sys/internal/; CEX DEX DECR ?
constexpr s64 PAID_76 = 0x107000040D000001L; // ?psp related?; ?/dev_flash/pspemu/release/?; CEX DEX DECR ?
constexpr s64 PAID_77 = 0x1070000500000001L; // cellftp; cell_root/target/images/; DECR
constexpr s64 PAID_78 = 0x1070000501000001L; // hdd_copy.self; CoreOS (since FW 3.10)
constexpr s64 PAID_79 = 0x10700005FC000001L; // sys_audio; /dev_flash/sys/internal; CEX
constexpr s64 PAID_80 = 0x10700005FD000001L; // sys_init_osd; /dev_flash/sys/internal; CEX
constexpr s64 PAID_81 = 0x10700005FF000001L; // vsh.self; /dev_flash/vsh/; CEX
constexpr s64 PAID_82 = 0x1070001002000001L; // PvrRecSvr.sprx; BCJB95006\USRDIR\v320; CEX
constexpr s64 PAID_83 = 0x1070200056000001L; // cachemgr.self; WebMAF apps/USRDIR
constexpr s64 PAID_84 = 0x1070200057000001L; // EBOOT.BIN.self + .sprx files; WebMAF apps/USRDIR/prx/ps3; Demen_prx.ppu.sprx + WebMAF sprx files
constexpr s64 PAID_85 = 0x1FF0000001000001L; // lv0; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_86 = 0x1FF0000002000001L; // lv1.self; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_87 = 0x1FF0000008000001L; // lv1ldr; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_88 = 0x1FF0000009000001L; // lv2ldr; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_89 = 0x1FF000000A000001L; // isoldr; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_90 = 0x1FF000000B000001L; // rvkldr; CoreOS; same for CEX DEX DECR
constexpr s64 PAID_91 = 0x1FF000000C000001L; // appldr; CoreOS; same for CEX DEX DECR

constexpr s64 LAID_1 = 0x1070000001000001L; // (= HV processes / SCE_CELLOS_PME); flash and vflash
constexpr s64 LAID_2 = 0x1070000002000001L; // (= GameOS / PS3_LPAR); flash and vflash
constexpr s64 LAID_3 = 0x1020000003000001L; // (= PS2_LPAR / PS2_GX_LPAR / PS2_SW_LPAR / PS2_NE_LPAR); (used in ps3vflashc region inside vflash in NOR consoles, and ps3db region)... dev_flash and dev_hdd0 regions
constexpr s64 LAID_4 = 0x1080000004000001L; // (= LINUX_LPAR); (used in ps3vflashf region inside vflash in NOR consoles)... otheros bootloader region

class KeyVault
{
	std::vector<SELF_KEY> sk_LV0_arr{};
	std::vector<SELF_KEY> sk_LV1_arr{};
	std::vector<SELF_KEY> sk_LV2_arr{};
	std::vector<SELF_KEY> sk_APP_arr{};
	std::vector<SELF_KEY> sk_ISO_arr{};
	std::vector<SELF_KEY> sk_LDR_arr{};
	std::vector<SELF_KEY> sk_UNK7_arr{};
	std::vector<SELF_KEY> sk_NPDRM_arr{};
	std::unique_ptr<u8[]> klicensee_key{};

public:
	KeyVault();
	SELF_KEY FindSelfKey(u32 type, u16 revision, u64 version);
	void SetKlicenseeKey(u8* key);
	u8* GetKlicenseeKey() const;

private:
	void LoadSelfLV0Keys();
	void LoadSelfLDRKeys();
	void LoadSelfLV1Keys();
	void LoadSelfLV2Keys();
	void LoadSelfISOKeys();
	void LoadSelfAPPKeys();
	void LoadSelfUNK7Keys();
	void LoadSelfNPDRMKeys();
	SELF_KEY GetSelfLV0Key() const;
	SELF_KEY GetSelfLDRKey() const;
	SELF_KEY GetSelfLV1Key(u64 version) const;
	SELF_KEY GetSelfLV2Key(u64 version) const;
	SELF_KEY GetSelfISOKey(u16 revision, u64 version) const;
	SELF_KEY GetSelfAPPKey(u16 revision) const;
	SELF_KEY GetSelfUNK7Key(u64 version) const;
	SELF_KEY GetSelfNPDRMKey(u16 revision) const;
};

// RAP to RIF function.
void rap_to_rif(unsigned char* rap, unsigned char* rif);
