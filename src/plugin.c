#if defined(WIN32) || defined(__WIN32__) || defined(_WIN32)
#pragma warning (disable : 4100)  /* Disable Unreferenced parameter warning */
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "teamspeak/public_errors.h"
#include "teamspeak/public_errors_rare.h"
#include "teamspeak/public_definitions.h"
#include "teamspeak/public_rare_definitions.h"
#include "teamspeak/clientlib_publicdefinitions.h"
#include "ts3_functions.h"
#include "plugin.h"

static struct TS3Functions ts3Functions;

#define PLUGIN_API_VERSION 23

const char* ts3plugin_name() {
	return "AutoMute";
}

const char* ts3plugin_version() {
    return "1.0";
}

int ts3plugin_apiVersion() {
	return PLUGIN_API_VERSION;
}

const char* ts3plugin_author() {
    return "Rene Hollander";
}

const char* ts3plugin_description() {
    return "Automatically mute everything on startup.";
}

void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
    ts3Functions = funcs;
}

int ts3plugin_init() {
    return 0;
}

void ts3plugin_shutdown() {
}

int ts3plugin_requestAutoload() {
	return 1;
}

void ts3plugin_onConnectStatusChangeEvent(uint64 serverConnectionHandlerID, int newStatus, unsigned int errorNumber) {
	ts3Functions.setClientSelfVariableAsInt(serverConnectionHandlerID, CLIENT_INPUT_MUTED, 1);
	ts3Functions.setClientSelfVariableAsInt(serverConnectionHandlerID, CLIENT_OUTPUT_MUTED, 1);
}
