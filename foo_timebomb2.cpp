#define _WIN32_WINNT _WIN32_WINNT_WIN7
#define WINVER _WIN32_WINNT_WIN7

#include <helpers/foobar2000+atl.h>

static constexpr const char* component_name = "Timebomb2";

DECLARE_COMPONENT_VERSION(
	component_name,
	"1.0",
	"grimes\n\n"
	"Build: " __TIME__ ", " __DATE__
);

VALIDATE_COMPONENT_FILENAME("foo_timebomb2.dll");

#define ID_TIMER2 1001

UINT_PTR ptr8 = 0;
pfc::string8 timebomb;
UINT bombtime;
bool menu_timebomb_enabled = false;

// {2E6AE435-C704-49F2-A6AD-C6DAAA6C4522}
static const GUID guid_cfg_branch = { 0x2e6ae435, 0xc704, 0x49f2, { 0xa6, 0xad, 0xc6, 0xda, 0xaa, 0x6c, 0x45, 0x22 } };
static advconfig_branch_factory cfg_branch("Timebomb", guid_cfg_branch, advconfig_entry::guid_branch_playback, 0);

// {FBA6BF11-0716-4FE9-A334-1AB1A53A4C91}
static const GUID guid_cfg_timebomb = { 0xfba6bf11, 0x716, 0x4fe9, { 0xa3, 0x34, 0x1a, 0xb1, 0xa5, 0x3a, 0x4c, 0x91 } };
advconfig_string_factory cfg_bpm("Time (min)", guid_cfg_timebomb, guid_cfg_branch, 0, "30");

VOID CALLBACK TimebombTimer(
	HWND hwnd,        // handle to window for timer messages
	UINT message,     // WM_TIMER message
	UINT idEvent1,     // timer identifier
	DWORD dwTime)     // current system time
{
	if (menu_timebomb_enabled)
	{
		static_api_ptr_t<playback_control>()->stop();
		FB2K_console_formatter() << "Timebomb stop";
		popup_message::g_show("Timebomb stop", "Information");
		menu_timebomb_enabled = false;
		KillTimer(NULL, idEvent1);
	}
	else
	{
		KillTimer(NULL, idEvent1);
	}
}

class mainmenu_commands_timebomb : public mainmenu_commands
{

public:

	// Return the number of commands we provide.
	virtual t_uint32 get_command_count()
	{
		return 1;
	}

	// All commands are identified by a GUID.
	virtual GUID get_command(t_uint32 p_index)
	{
		// {B2E8A120-2174-4F0E-BF6A-2EF475303CCA}
		static const GUID guid_main_timebomb =
		{ 0xb2e8a120, 0x2174, 0x4f0e, { 0xbf, 0x6a, 0x2e, 0xf4, 0x75, 0x30, 0x3c, 0xca } };

		if (p_index == 0)
			return guid_main_timebomb;
		return pfc::guid_null;
	}

	// Set p_out to the name of the n-th command.
	// This name is used to identify the command and determines
	// the default position of the command in the menu.
	virtual void get_name(t_uint32 p_index, pfc::string_base& p_out)
	{
		if (p_index == 0)
			p_out = "Timebomb";
	}

	// Set p_out to the description for the n-th command.
	virtual bool get_description(t_uint32 p_index, pfc::string_base& p_out)
	{
		if (p_index == 0)
			p_out = "Toogle timebomb";
		else
			return false;
		return true;
	}

	// Every set of commands needs to declare which group it belongs to.
	virtual GUID get_parent()
	{
		return mainmenu_groups::playback;
	}

	// Execute n-th command.
	// p_callback is reserved for future use.
	virtual void execute(t_uint32 p_index, service_ptr_t<service_base> p_callback)
	{
		if (p_index == 0)
		{
			menu_timebomb_enabled = !menu_timebomb_enabled;
			if (menu_timebomb_enabled)
			{
				cfg_bpm.get(timebomb);
				bombtime = atoi(timebomb);
				ptr8 = SetTimer(NULL, ID_TIMER2, bombtime * 1000 * 60, (TIMERPROC)TimebombTimer);
				FB2K_console_formatter() << "Timebomb started: " << timebomb << "min";
			}
			else
			{
				KillTimer(NULL, ptr8);
				FB2K_console_formatter() << "Timebomb aborted";
			}
		}
	}

	// The standard version of this command does not support checked or disabled
	// commands, so we use our own version.
	virtual bool get_display(t_uint32 p_index, pfc::string_base& p_text, t_uint32& p_flags)
	{
		if (p_index == 0) {
			get_name(p_index, p_text);
			if (menu_timebomb_enabled)
			{
				p_flags |= flag_checked;
			}
		}
		return true;
	}
	virtual t_uint32 get_sort_priority()
	{
		return sort_priority_dontcare;
	}
	bool is_checked(t_uint32 p_index)
	{
		if (p_index == 0)
			return menu_timebomb_enabled;
	}
};

static mainmenu_commands_factory_t<mainmenu_commands_timebomb> g_mainmenu_commands_timebomb;