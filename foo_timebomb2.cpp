#define _WIN32_WINNT _WIN32_WINNT_WIN7
#define WINVER _WIN32_WINNT_WIN7

#include <helpers/foobar2000+atl.h>

static constexpr const char* component_name = "Timebomb2";

DECLARE_COMPONENT_VERSION(
	component_name,
	"1.2",
	"grimes\n\n"
	"Build: " __TIME__ ", " __DATE__
);

VALIDATE_COMPONENT_FILENAME("foo_timebomb2.dll");

#define ID_TIMER2 1001

UINT_PTR ptr8 = 0;
pfc::string8 timebomb;
UINT timebomb2;

// {1094D78B-67D9-4D99-BE29-493F7CDA04B8}
static const GUID guid_cfg_menu_timebomb_enabled = { 0x1094d78b, 0x67d9, 0x4d99, { 0xbe, 0x29, 0x49, 0x3f, 0x7c, 0xda, 0x4, 0xb8 } };
cfg_bool cfg_menu_timebomb_enabled(guid_cfg_menu_timebomb_enabled, false);

VOID CALLBACK TimebombTimer(
	HWND hwnd,        // handle to window for timer messages
	UINT message,     // WM_TIMER message
	UINT idEvent1,     // timer identifier
	DWORD dwTime)     // current system time
{
	if (cfg_menu_timebomb_enabled)
	{
		static_api_ptr_t<playback_control>()->stop();
		FB2K_console_formatter() << "Timebomb stop";
		popup_message::g_show("Timebomb stop", "Information");
		cfg_menu_timebomb_enabled = false;
		KillTimer(NULL, idEvent1);
	}
	else
	{
		KillTimer(NULL, idEvent1);
	}
}

// {2E6AE435-C704-49F2-A6AD-C6DAAA6C4522}
static const GUID guid_cfg_branch = { 0x2e6ae435, 0xc704, 0x49f2, { 0xa6, 0xad, 0xc6, 0xda, 0xaa, 0x6c, 0x45, 0x22 } };
static advconfig_branch_factory cfg_branch("Timebomb", guid_cfg_branch, advconfig_entry::guid_branch_playback, 0);

// {FBA6BF11-0716-4FE9-A334-1AB1A53A4C91}
static const GUID guid_cfg_timebomb = { 0xfba6bf11, 0x716, 0x4fe9, { 0xa3, 0x34, 0x1a, 0xb1, 0xa5, 0x3a, 0x4c, 0x91 } };
advconfig_string_factory cfg_timebomb("Time (min)", guid_cfg_timebomb, guid_cfg_branch, 0, "1");

// {0C6EF789-B23C-49CF-97AF-B27B44F1A2DA}
static const GUID guid_cfg_menu_timebomb =
{ 0xc6ef789, 0xb23c, 0x49cf, { 0x97, 0xaf, 0xb2, 0x7b, 0x44, 0xf1, 0xa2, 0xda } };

// {FF256F9B-251B-4C31-8381-718429A4C7E4}
static const GUID guid_cfg_menu_timebomb1_enabled = { 0xff256f9b, 0x251b, 0x4c31, { 0x83, 0x81, 0x71, 0x84, 0x29, 0xa4, 0xc7, 0xe4 } };
cfg_bool cfg_menu_timebomb1_enabled(guid_cfg_menu_timebomb1_enabled, false);

// {C042AA8F-AF76-4FA8-B616-849A0789DC78}
static const GUID guid_cfg_menu_timebomb2_enabled = { 0xc042aa8f, 0xaf76, 0x4fa8, { 0xb6, 0x16, 0x84, 0x9a, 0x7, 0x89, 0xdc, 0x78 } };
cfg_bool cfg_menu_timebomb2_enabled(guid_cfg_menu_timebomb2_enabled, false);

// {A6EB1B11-2886-4AF6-A86A-996D2F3A11A3}
static const GUID guid_cfg_menu_timebomb3_enabled = { 0xa6eb1b11, 0x2886, 0x4af6, { 0xa8, 0x6a, 0x99, 0x6d, 0x2f, 0x3a, 0x11, 0xa3 } };
cfg_bool cfg_menu_timebomb3_enabled(guid_cfg_menu_timebomb3_enabled, false);

// {FCEE1186-506C-4504-9F8E-7EEA12E236D1}
static const GUID guid_cfg_menu_timebomb4_enabled = { 0xfcee1186, 0x506c, 0x4504, { 0x9f, 0x8e, 0x7e, 0xea, 0x12, 0xe2, 0x36, 0xd1 } };
cfg_bool cfg_menu_timebomb4_enabled(guid_cfg_menu_timebomb4_enabled, false);

// {F78A71F5-BB74-44B4-A865-832218EACE61}
static const GUID guid_cfg_menu_timebomb5_enabled = { 0xf78a71f5, 0xbb74, 0x44b4, { 0xa8, 0x65, 0x83, 0x22, 0x18, 0xea, 0xce, 0x61 } };
cfg_bool cfg_menu_timebomb5_enabled(guid_cfg_menu_timebomb5_enabled, false);

// {9FB65CEB-6AA6-4937-A46B-66C2A3A00676}
static const GUID guid_cfg_menu_timebomb6_enabled = { 0x9fb65ceb, 0x6aa6, 0x4937, { 0xa4, 0x6b, 0x66, 0xc2, 0xa3, 0xa0, 0x6, 0x76 } };
cfg_bool cfg_menu_timebomb6_enabled(guid_cfg_menu_timebomb6_enabled, false);

// {7920076F-4601-4AC8-943E-75508CA41D44}
static const GUID guid_cfg_menu_timebomb7_enabled = { 0x7920076f, 0x4601, 0x4ac8, { 0x94, 0x3e, 0x75, 0x50, 0x8c, 0xa4, 0x1d, 0x44 } };
cfg_bool cfg_menu_timebomb7_enabled(guid_cfg_menu_timebomb7_enabled, false);

// {A5CAB296-D158-4020-AD8E-A921FA993B52}
static const GUID guid_cfg_menu_timebomb8_enabled = { 0xa5cab296, 0xd158, 0x4020, { 0xad, 0x8e, 0xa9, 0x21, 0xfa, 0x99, 0x3b, 0x52 } };
cfg_bool cfg_menu_timebomb8_enabled(guid_cfg_menu_timebomb8_enabled, false);

// {AD8897A7-6C89-4E28-946C-F1D76F6B858F}
static const GUID guid_cfg_menu_timebomb9_enabled = { 0xad8897a7, 0x6c89, 0x4e28, { 0x94, 0x6c, 0xf1, 0xd7, 0x6f, 0x6b, 0x85, 0x8f } };
cfg_bool cfg_menu_timebomb9_enabled(guid_cfg_menu_timebomb9_enabled, false);

// {B97B45A1-CA22-4F2F-8A32-0A6643E688F7}
static const GUID guid_cfg_menu_timebomb10_enabled = { 0xb97b45a1, 0xca22, 0x4f2f, { 0x8a, 0x32, 0xa, 0x66, 0x43, 0xe6, 0x88, 0xf7 } };
cfg_bool cfg_menu_timebomb10_enabled(guid_cfg_menu_timebomb10_enabled, false);

// {E3666D68-F375-4669-A0F7-447A632A31DE}
static const GUID guid_cfg_menu_timebomb11_enabled = { 0xe3666d68, 0xf375, 0x4669, { 0xa0, 0xf7, 0x44, 0x7a, 0x63, 0x2a, 0x31, 0xde } };
cfg_bool cfg_menu_timebomb11_enabled(guid_cfg_menu_timebomb11_enabled, false);

class mainmenu_commands_timebomb : public mainmenu_commands
{

public:

	// Return the number of commands we provide.
	virtual t_uint32 get_command_count()
	{
		return 12;
	}

	// All commands are identified by a GUID.
	virtual GUID get_command(t_uint32 p_index)
	{
		// {0ECA36EF-3A13-4A67-ADD8-1F7A752B46E1}
		static const GUID guid_main_timebomb1_toggle = { 0xeca36ef, 0x3a13, 0x4a67, { 0xad, 0xd8, 0x1f, 0x7a, 0x75, 0x2b, 0x46, 0xe1 } };
		// {5F8C2455-7EF2-4BAE-8C68-B6419A152487}
		static const GUID guid_main_timebomb2_toggle = { 0x5f8c2455, 0x7ef2, 0x4bae, { 0x8c, 0x68, 0xb6, 0x41, 0x9a, 0x15, 0x24, 0x87 } };
		// {75B9ADC3-8441-4B33-80CA-A3299D3DCF77}
		static const GUID guid_main_timebomb3_toggle = { 0x75b9adc3, 0x8441, 0x4b33, { 0x80, 0xca, 0xa3, 0x29, 0x9d, 0x3d, 0xcf, 0x77 } };
		// {AD0C0D0B-AA51-421B-B029-A0041319A54A}
		static const GUID guid_main_timebomb4_toggle = { 0xad0c0d0b, 0xaa51, 0x421b, { 0xb0, 0x29, 0xa0, 0x4, 0x13, 0x19, 0xa5, 0x4a } };
		// {55D0FC65-07B4-4D17-BDC3-81A54E0A462D}
		static const GUID guid_main_timebomb5_toggle = { 0x55d0fc65, 0x7b4, 0x4d17, { 0xbd, 0xc3, 0x81, 0xa5, 0x4e, 0xa, 0x46, 0x2d } };
		// {0BA2156B-0E98-41BC-B928-AE037926526F}
		static const GUID guid_main_timebomb6_toggle = { 0xba2156b, 0xe98, 0x41bc, { 0xb9, 0x28, 0xae, 0x3, 0x79, 0x26, 0x52, 0x6f } };
		// {19B26A7D-F346-48C0-A428-218E6F44199E}
		static const GUID guid_main_timebomb7_toggle = { 0x19b26a7d, 0xf346, 0x48c0, { 0xa4, 0x28, 0x21, 0x8e, 0x6f, 0x44, 0x19, 0x9e } };
		// {B59F606E-C4C5-4165-BC83-D9B35CC7E9D2}
		static const GUID guid_main_timebomb8_toggle = { 0xb59f606e, 0xc4c5, 0x4165, { 0xbc, 0x83, 0xd9, 0xb3, 0x5c, 0xc7, 0xe9, 0xd2 } };
		// {4ABD14C9-FEB4-482B-B7B9-EEA73E9281DA}
		static const GUID guid_main_timebomb9_toggle = { 0x4abd14c9, 0xfeb4, 0x482b, { 0xb7, 0xb9, 0xee, 0xa7, 0x3e, 0x92, 0x81, 0xda } };
		// {8F8C5BB7-91D2-44DF-B3D6-398D72D9FBAE}
		static const GUID guid_main_timebomb10_toggle = { 0x8f8c5bb7, 0x91d2, 0x44df, { 0xb3, 0xd6, 0x39, 0x8d, 0x72, 0xd9, 0xfb, 0xae } };
		// {1DEABE4F-F2F1-4452-A6CB-0CA1FC10848C}
		static const GUID guid_main_timebomb11_toggle = { 0x1deabe4f, 0xf2f1, 0x4452, { 0xa6, 0xcb, 0xc, 0xa1, 0xfc, 0x10, 0x84, 0x8c } };
		// {6A9E9335-3D2E-4A1B-800D-9032246010D9}
		static const GUID guid_main_timebomb12_toggle = { 0x6a9e9335, 0x3d2e, 0x4a1b, { 0x80, 0xd, 0x90, 0x32, 0x24, 0x60, 0x10, 0xd9 } };
		
		if (p_index == 0)
			return guid_main_timebomb1_toggle;
		if (p_index == 1)
			return guid_main_timebomb2_toggle;
		if (p_index == 2)
			return guid_main_timebomb3_toggle;
		if (p_index == 3)
			return guid_main_timebomb4_toggle;
		if (p_index == 4)
			return guid_main_timebomb5_toggle;
		if (p_index == 5)
			return guid_main_timebomb6_toggle;
		if (p_index == 6)
			return guid_main_timebomb7_toggle;
		if (p_index == 7)
			return guid_main_timebomb8_toggle;
		if (p_index == 8)
			return guid_main_timebomb9_toggle;
		if (p_index == 9)
			return guid_main_timebomb10_toggle;
		if (p_index == 10)
			return guid_main_timebomb11_toggle;
		if (p_index == 11)
			return guid_main_timebomb12_toggle;
		return pfc::guid_null;
	}

	// Set p_out to the name of the n-th command.
	// This name is used to identify the command and determines
	// the default position of the command in the menu.
	virtual void get_name(t_uint32 p_index, pfc::string_base& p_out)
	{
		if (p_index == 0)
			p_out = "15min";
		if (p_index == 1)
			p_out = "30min";
		if (p_index == 2)
			p_out = "1h";
		if (p_index == 3)
			p_out = "1.5h";
		if (p_index == 4)
			p_out = "2h";
		if (p_index == 5)
			p_out = "2.5h";
		if (p_index == 6)
			p_out = "3h";
		if (p_index == 7)
			p_out = "3.5h";
		if (p_index == 8)
			p_out = "4h";
		if (p_index == 9)
			p_out = "4.5h";
		if (p_index == 10)
			p_out = "Custom";
		if (p_index == 11)
			p_out = "Timebomb";

	}

	// Set p_out to the description for the n-th command.
	virtual bool get_description(t_uint32 p_index, pfc::string_base& p_out)
	{
		if (p_index == 0)
			p_out = "Stop playback after 15min.";
		else if (p_index == 1)
			p_out = "Stop playback after 30min.";
		else if (p_index == 2)
			p_out = "Stop playback after 1h.";
		else if (p_index == 3)
			p_out = "Stop playback after 1.5h.";
		else if (p_index == 4)
			p_out = "Stop playback after 2h.";
		else if (p_index == 5)
			p_out = "Stop playback after 2.5h.";
		else if (p_index == 6)
			p_out = "Stop playback after 3h.";
		else if (p_index == 7)
			p_out = "Stop playback after 3.5h.";
		else if (p_index == 8)
			p_out = "Stop playback after 4h.";
		else if (p_index == 9)
			p_out = "Stop playback after 4.5h.";
		else if (p_index == 10)
			p_out = "Stop playback after custom minutes.";
		else if (p_index == 11)
			p_out = "Timebomb";
		else
			return false;
		return true;
	}

	// Every set of commands needs to declare which group it belongs to.
	virtual GUID get_parent()
	{
		return guid_cfg_menu_timebomb;
	}

	// Execute n-th command.
	// p_callback is reserved for future use.
	virtual void execute(t_uint32 p_index, service_ptr_t<service_base> p_callback)
	{
		if (p_index == 0 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb1_enabled = true;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 30;
		}
		if (p_index == 1 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb2_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 60;
		}
		if (p_index == 2 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb3_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 90;
		}
		if (p_index == 3 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb4_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 120;
		}
		if (p_index == 4 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb5_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 150;
		}
		if (p_index == 5 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb6_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 180;
		}
		if (p_index == 6 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb7_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 210;
		}
		if (p_index == 7 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb8_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 240;
		}
		if (p_index == 8 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb9_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 270;
		}
		if (p_index == 9 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb10_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb11_enabled = false;
			timebomb2 = 300;
		}
		if (p_index == 10 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb11_enabled = true;
			cfg_menu_timebomb1_enabled = false;
			cfg_menu_timebomb2_enabled = false;
			cfg_menu_timebomb3_enabled = false;
			cfg_menu_timebomb4_enabled = false;
			cfg_menu_timebomb5_enabled = false;
			cfg_menu_timebomb6_enabled = false;
			cfg_menu_timebomb7_enabled = false;
			cfg_menu_timebomb8_enabled = false;
			cfg_menu_timebomb9_enabled = false;
			cfg_menu_timebomb10_enabled = false;
			cfg_timebomb.get(timebomb);
			timebomb2 = atoi(timebomb);
		}
		if (p_index == 11 && core_api::assert_main_thread())
		{
			cfg_menu_timebomb_enabled = !cfg_menu_timebomb_enabled;
			if (cfg_menu_timebomb_enabled)
			{
				if (cfg_menu_timebomb1_enabled)
				{
					timebomb2 = 15;
				}
				else if (cfg_menu_timebomb2_enabled)
				{
					timebomb2 = 30;
				}
				else if (cfg_menu_timebomb3_enabled)
				{
					timebomb2 = 60;
				}
				else if (cfg_menu_timebomb4_enabled)
				{
					timebomb2 = 90;
				}
				else if (cfg_menu_timebomb5_enabled)
				{
					timebomb2 = 120;
				}
				else if (cfg_menu_timebomb6_enabled)
				{
					timebomb2 = 150;
				}
				else if (cfg_menu_timebomb7_enabled)
				{
					timebomb2 = 180;
				}
				else if (cfg_menu_timebomb8_enabled)
				{
					timebomb2 = 210;
				}
				else if (cfg_menu_timebomb9_enabled)
				{
					timebomb2 = 240;
				}
				else if (cfg_menu_timebomb10_enabled)
				{
					timebomb2 = 270;
				}
				else if (cfg_menu_timebomb11_enabled)
				{
					cfg_timebomb.get(timebomb);
					timebomb2 = atoi(timebomb);
				}
				ptr8 = SetTimer(NULL, ID_TIMER2, timebomb2 * 1000 * 60, (TIMERPROC)TimebombTimer);
				FB2K_console_formatter() << "Timebomb in " << timebomb2 << "min";
			}
			else
			{
				FB2K_console_formatter() << "Timebomb aborted";
			}
		}
	}

	// The standard version of this command does not support checked or disabled
	// commands, so we use our own version.
	virtual bool get_display(t_uint32 p_index, pfc::string_base& p_text, t_uint32& p_flags)
	{
		p_flags = 0;
		if (p_index < 11)
		{
			if (is_checked(p_index))
				p_flags |= flag_radiochecked;
			get_name(p_index, p_text);
		}
		if (p_index == 11) {
			if (is_checked(p_index))
			{
				p_flags |= flag_checked;
			}
			else {
				p_flags = 0;
			}
			get_name(p_index, p_text);
		}
		return true;
	}

	virtual t_uint32 get_sort_priority()
	{
		return sort_priority_base;
	}

private:

	// Return whether the n-th command is checked.
	bool is_checked(t_uint32 p_index)
	{
		if (p_index == 0)
		{
			return cfg_menu_timebomb1_enabled;
		}
		if (p_index == 1)
		{
			return cfg_menu_timebomb2_enabled;
		}
		if (p_index == 2)
		{
			return cfg_menu_timebomb3_enabled;
		}
		if (p_index == 3)
		{
			return cfg_menu_timebomb4_enabled;
		}
		if (p_index == 4)
		{
			return cfg_menu_timebomb5_enabled;
		}
		if (p_index == 5)
		{
			return cfg_menu_timebomb6_enabled;
		}
		if (p_index == 6)
		{
			return cfg_menu_timebomb7_enabled;
		}
		if (p_index == 7)
		{
			return cfg_menu_timebomb8_enabled;
		}
		if (p_index == 8)
		{
			return cfg_menu_timebomb9_enabled;
		}
		if (p_index == 9)
		{
			return cfg_menu_timebomb10_enabled;
		}
		if (p_index == 10)
		{
			return cfg_menu_timebomb11_enabled;
		}
		if (p_index == 11)
		{
			return cfg_menu_timebomb_enabled;
		}
		return false;
	}
};


static mainmenu_group_popup_factory mainmenu_group(guid_cfg_menu_timebomb,
	mainmenu_groups::playback, mainmenu_commands::sort_priority_base,
	"Timebomb");


static mainmenu_commands_factory_t<mainmenu_commands_timebomb> g_mainmenu_commands_timebomb;