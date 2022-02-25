#pragma once

#ifdef _WIN64

#pragma comment(linker, "/export:UPLAY_FRIENDS_DisableFriendMenuItem=uplay_r1_loader64_o.UPLAY_FRIENDS_DisableFriendMenuItem")
#pragma comment(linker, "/export:UPLAY_FRIENDS_EnableFriendMenuItem=uplay_r1_loader64_o.UPLAY_FRIENDS_EnableFriendMenuItem")
#pragma comment(linker, "/export:UPLAY_PARTY_DisablePartyMemberMenuItem=uplay_r1_loader64_o.UPLAY_PARTY_DisablePartyMemberMenuItem")
#pragma comment(linker, "/export:UPLAY_PARTY_EnablePartyMemberMenuItem=uplay_r1_loader64_o.UPLAY_PARTY_EnablePartyMemberMenuItem")
#pragma comment(linker, "/export:UPLAY_PARTY_SetGuest=uplay_r1_loader64_o.UPLAY_PARTY_SetGuest")

#else

#pragma comment(linker, "/export:UPLAY_FRIENDS_DisableFriendMenuItem=uplay_r1_loader_o.UPLAY_FRIENDS_DisableFriendMenuItem")
#pragma comment(linker, "/export:UPLAY_FRIENDS_EnableFriendMenuItem=uplay_r1_loader_o.UPLAY_FRIENDS_EnableFriendMenuItem")
#pragma comment(linker, "/export:UPLAY_PARTY_DisablePartyMemberMenuItem=uplay_r1_loader_o.UPLAY_PARTY_DisablePartyMemberMenuItem")
#pragma comment(linker, "/export:UPLAY_PARTY_EnablePartyMemberMenuItem=uplay_r1_loader_o.UPLAY_PARTY_EnablePartyMemberMenuItem")
#pragma comment(linker, "/export:UPLAY_PARTY_SetGuest=uplay_r1_loader_o.UPLAY_PARTY_SetGuest")

#endif
