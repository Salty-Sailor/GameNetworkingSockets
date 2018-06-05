//====== Copyright Valve Corporation, All rights reserved. ====================
//
// Plain C interface to SteamNetworkingSockets
//
// Designed to match the auto-generated flat interface in the Steamworks SDK
// (for better or worse...)
//
//=============================================================================

#ifndef STEAMNETWORKINGSOCKETS_FLAT
#define STEAMNETWORKINGSOCKETS_FLAT
#pragma once

#include <stdint.h>
#include <deque>
#include <string>
#include <iostream>
#include "isteamnetworkingsockets.h"
#include "steamnetworkingtypes.h"

extern "C" {

STEAMNETWORKINGSOCKETS_INTERFACE HSteamListenSocket SteamAPI_ISteamNetworkingSockets_CreateListenSocket( intptr_t instancePtr, int nSteamConnectVirtualPort, uint32 nIP, uint16 nPort );

#ifndef STEAMNETWORKINGSOCKETS_OPENSOURCE
STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectBySteamID( intptr_t instancePtr, CSteamID steamIDTarget, int nVirtualPort );
#endif

STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectByIPv4Address( intptr_t instancePtr, uint32 nIP, uint16 nPort );
STEAMNETWORKINGSOCKETS_INTERFACE EResult SteamAPI_ISteamNetworkingSockets_AcceptConnection( intptr_t instancePtr, HSteamNetConnection hConn );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_CloseConnection( intptr_t instancePtr, HSteamNetConnection hPeer, int nReason, const char *pszDebug, bool bEnableLinger );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_CloseListenSocket( intptr_t instancePtr, HSteamListenSocket hSocket, const char *pszNotifyRemoteReason );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_SetConnectionUserData( intptr_t instancePtr, HSteamNetConnection hPeer, int64 nUserData );
STEAMNETWORKINGSOCKETS_INTERFACE int64 SteamAPI_ISteamNetworkingSockets_GetConnectionUserData( intptr_t instancePtr, HSteamNetConnection hPeer );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_ISteamNetworkingSockets_SetConnectionName( intptr_t instancePtr, HSteamNetConnection hPeer, const char *pszName );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetConnectionName( intptr_t instancePtr, HSteamNetConnection hPeer, char *pszName, int nMaxLen );
STEAMNETWORKINGSOCKETS_INTERFACE EResult SteamAPI_ISteamNetworkingSockets_SendMessageToConnection( intptr_t instancePtr, HSteamNetConnection hConn, const void *pData, uint32 cbData, ESteamNetworkingSendType eSendType );
STEAMNETWORKINGSOCKETS_INTERFACE EResult SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection( intptr_t instancePtr, HSteamNetConnection hConn );
STEAMNETWORKINGSOCKETS_INTERFACE int SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection( intptr_t instancePtr, HSteamNetConnection hConn, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages ); 
STEAMNETWORKINGSOCKETS_INTERFACE int SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnListenSocket( intptr_t instancePtr, HSteamListenSocket hSocket, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages ); 
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetConnectionInfo( intptr_t instancePtr, HSteamNetConnection hConn, SteamNetConnectionInfo_t *pInfo );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetQuickConnectionStatus( intptr_t instancePtr, HSteamNetConnection hConn, SteamNetworkingQuickConnectionStatus *pStats );
STEAMNETWORKINGSOCKETS_INTERFACE int SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus( intptr_t instancePtr, HSteamNetConnection hConn, char *pszBuf, int cbBuf );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetListenSocketInfo( intptr_t instancePtr, HSteamListenSocket hSocket, uint32 *pnIP, uint16 *pnPort );

STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_CreateSocketPair( intptr_t instancePtr, HSteamNetConnection *pOutConnection1, HSteamNetConnection *pOutConnection2, bool bUseNetworkLoopback );

#ifndef STEAMNETWORKINGSOCKETS_OPENSOURCE

STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket( intptr_t instancePtr, const void *pvTicket, int cbTicket, SteamDatagramRelayAuthTicket *pOutParsedTicket );
STEAMNETWORKINGSOCKETS_INTERFACE int SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer( intptr_t instancePtr, CSteamID steamID, int nVirtualPort, SteamDatagramRelayAuthTicket *pOutParsedTicket );
STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer( intptr_t instancePtr, CSteamID steamIDTarget, int nVirtualPort );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerInfo( intptr_t instancePtr, SteamDatagramServiceNetID *pRouting, SteamNetworkingPOPID *pPopID );
STEAMNETWORKINGSOCKETS_INTERFACE HSteamListenSocket SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket( intptr_t instancePtr, int nVirtualPort );

#endif // #ifndef STEAMNETWORKINGSOCKETS_OPENSOURCE

STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetConnectionDebugText( intptr_t instancePtr, HSteamNetConnection hConn, char *pOut, int nOutCCH );
STEAMNETWORKINGSOCKETS_INTERFACE int32 SteamAPI_ISteamNetworkingSockets_GetConfigurationValue( intptr_t instancePtr, ESteamNetworkingConfigurationValue eConfigValue );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_SetConfigurationValue( intptr_t instancePtr, ESteamNetworkingConfigurationValue eConfigValue, int32 nValue );
STEAMNETWORKINGSOCKETS_INTERFACE const char *SteamAPI_ISteamNetworkingSockets_GetConfigurationValueName( intptr_t instancePtr, ESteamNetworkingConfigurationValue eConfigValue );
STEAMNETWORKINGSOCKETS_INTERFACE int32 SteamAPI_ISteamNetworkingSockets_GetConfigurationString( intptr_t instancePtr, ESteamNetworkingConfigurationString eConfigString, char *pDest, int32 destSize );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_SetConfigurationString( intptr_t instancePtr, ESteamNetworkingConfigurationString eConfigString, const char *pString );
STEAMNETWORKINGSOCKETS_INTERFACE const char *SteamAPI_ISteamNetworkingSockets_GetConfigurationStringName( intptr_t instancePtr, ESteamNetworkingConfigurationString eConfigString );
STEAMNETWORKINGSOCKETS_INTERFACE int32 SteamAPI_ISteamNetworkingSockets_GetConnectionConfigurationValue( intptr_t instancePtr, HSteamNetConnection hConn, ESteamNetworkingConnectionConfigurationValue eConfigValue );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_SetConnectionConfigurationValue( intptr_t instancePtr, HSteamNetConnection hConn, ESteamNetworkingConnectionConfigurationValue eConfigValue, int32 nValue );

// Temporarily callback dispatch mechanism.  Eventually in Steamworks
// this function won't exist, the callbacks will be dispatched through the
// SteamAPI_RunCallbacks method, and this will only be used in the opensource
// version.
typedef void (*FSteamNetConnectionStatusChangedCallback)( SteamNetConnectionStatusChangedCallback_t *pInfo, intptr_t context );
STEAMNETWORKINGSOCKETS_INTERFACE void GameNetworkingSockets_RunConnectionStatusChangedCallbacks( intptr_t instancePtr, FSteamNetConnectionStatusChangedCallback callback, intptr_t context );

}

#endif // ISTEAMNETWORKINGSOCKETS

extern "C" {
    STEAMNETWORKINGSOCKETS_INTERFACE void TickCallBacks(ISteamNetworkingSockets *pInterface);
    STEAMNETWORKINGSOCKETS_INTERFACE void ClearEventsQuene();
    STEAMNETWORKINGSOCKETS_INTERFACE int HandleEvents(HSteamNetConnection *accept, HSteamNetConnection *close, HSteamNetConnection *connected);
    STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection HandleConnectionAccept();
    STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection HandleConnectionClose();
    STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection HandleConnectionConnected();

    STEAMNETWORKINGSOCKETS_INTERFACE uint32 GetMessageSize(ISteamNetworkingMessage **message);
    STEAMNETWORKINGSOCKETS_INTERFACE const void *GetMessagePayLoad(ISteamNetworkingMessage **message);
    STEAMNETWORKINGSOCKETS_INTERFACE void ReleaseMessage(ISteamNetworkingMessage **message);
}

extern "C" {
    struct SandboxCallbacks : public ISteamNetworkingSocketsCallbacks {
        std::deque<HSteamNetConnection> _close;
        std::deque<HSteamNetConnection> _accept;
        std::deque<HSteamNetConnection> _connected;

        SandboxCallbacks() {
            _close = std::deque<HSteamNetConnection>();
            _accept = std::deque<HSteamNetConnection>();
            _connected = std::deque<HSteamNetConnection>();
        };
        virtual ~SandboxCallbacks() {}
        virtual void OnSteamNetConnectionStatusChanged( SteamNetConnectionStatusChangedCallback_t *pInfo ) override {
            switch ( pInfo->m_info.m_eState ) {
                case k_ESteamNetworkingConnectionState_ClosedByPeer:
                case k_ESteamNetworkingConnectionState_ProblemDetectedLocally:
                    printf( "Steam Net connection %x %s, reason %d: %s\n",
                            pInfo->m_hConn,
                            ( pInfo->m_info.m_eState == k_ESteamNetworkingConnectionState_ClosedByPeer ? "closed by peer" : "problem detected locally" ),
                            pInfo->m_info.m_eEndReason,
                            pInfo->m_info.m_szEndDebug
                    );

                    // Close our end
                    SteamNetworkingSockets()->CloseConnection( pInfo->m_hConn, 0, nullptr, false );
                    _close.push_back(pInfo->m_hConn);

                    break;

                case k_ESteamNetworkingConnectionState_Connecting:
                    printf( "Accepting Steam Net connection %x\n", pInfo->m_hConn );
                    _accept.push_back(pInfo->m_hConn);

                    break;

                case k_ESteamNetworkingConnectionState_Connected:
                    _connected.push_back(pInfo->m_hConn);
                    printf( "Connected Steam Net connection %x\n", pInfo->m_hConn );

                    break;
            }
        }

        void ClearEventsQuene() {
            _close.clear();
            _accept.clear();
            _connected.clear();
        }
    };
}

