/*
 * Copyright (C) 2009 Daniel-Constantin Mierla (asipto.com)
 *
 * This file is part of kamailio, a free SIP server.
 *
 * Kamailio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * Kamailio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _UAC_SEND_H_
#define _UAC_SEND_H_

#include "../../core/pvar.h"
#include "../../core/str.h"

#define UAC_SEND_FL_HA1 (1 << 0)
#define MAX_UACH_SIZE 2048
#define MAX_UACB_SIZE 32768
#define MAX_UACD_SIZE 128
#define MAX_UAC_LUUID_SIZE 256

typedef struct _uac_send_info
{
	unsigned int flags;
	char b_method[32];
	str s_method;
	char b_ruri[MAX_URI_SIZE];
	str s_ruri;
	char b_turi[MAX_URI_SIZE];
	str s_turi;
	char b_ttag[128];
	str s_ttag;
	char b_furi[MAX_URI_SIZE];
	str s_furi;
	char b_ftag[128];
	str s_ftag;
	char b_callid[128];
	str s_callid;
	char b_hdrs[MAX_UACH_SIZE];
	str s_hdrs;
	char b_body[MAX_UACB_SIZE];
	str s_body;
	char b_ouri[MAX_URI_SIZE];
	str s_ouri;
	char b_sock[MAX_URI_SIZE];
	str s_sock;
	char b_auser[128];
	str s_auser;
	char b_apasswd[64];
	str s_apasswd;
	char b_evparam[MAX_UACD_SIZE];
	str s_evparam;
	char b_l_uuid[MAX_UAC_LUUID_SIZE];
	str s_l_uuid;
	unsigned int cseqno;
	unsigned int fr_timeout;
	unsigned int fr_inv_timeout;
	unsigned int evroute;
	unsigned int evcode;
	unsigned int evtype;
} uac_send_info_t;

void uac_send_info_init(uac_send_info_t *info);
void uac_send_info_copy(uac_send_info_t *src, uac_send_info_t *dst);
uac_send_info_t *uac_send_info_clone(uac_send_info_t *ur);
void uac_req_run_event_route(sip_msg_t *msg, uac_send_info_t *tp, int rcode);

int pv_get_uac_req(struct sip_msg *msg, pv_param_t *param, pv_value_t *res);
int pv_set_uac_req(
		struct sip_msg *msg, pv_param_t *param, int op, pv_value_t *val);
int pv_parse_uac_req_name(pv_spec_p sp, str *in);
void uac_req_init(void);
int uac_req_send(void);
int w_uac_req_send(struct sip_msg *msg, char *s1, char *s2);
int ki_uac_req_send(sip_msg_t *msg);

#endif
