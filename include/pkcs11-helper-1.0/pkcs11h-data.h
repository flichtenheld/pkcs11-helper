/*
 * Copyright (c) 2005-2006 Alon Bar-Lev <alon.barlev@gmail.com>
 * All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, or the OpenIB.org BSD license.
 *
 * GNU General Public License (GPL) Version 2
 * ===========================================
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program (see the file COPYING[.GPL2] included with this
 *  distribution); if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * OpenIB.org BSD license
 * =======================
 * Redistribution and use in source and binary forms, with or without modifi-
 * cation, are permitted provided that the following conditions are met:
 *
 *   o  Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *   o  Redistributions in binary form must reproduce the above copyright no-
 *      tice, this list of conditions and the following disclaimer in the do-
 *      cumentation and/or other materials provided with the distribution.
 *
 *   o  The names of the contributors may not be used to endorse or promote
 *      products derived from this software without specific prior written
 *      permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LI-
 * ABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUEN-
 * TIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEV-
 * ER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABI-
 * LITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file pkcs11h-data.h
 * @brief pkcs11-helper data object support.
 * @author Alon Bar-Lev <alon.barlev@gmail.com>
 */

#ifndef __PKCS11H_DATA_H
#define __PKCS11H_DATA_H

#include <pkcs11-helper-1.0/pkcs11h-core.h>

#if defined(__cplusplus)
extern "C" {
#endif

struct pkcs11h_data_id_list_s;

/**
 * @brief Data identifier list.
 */
typedef struct pkcs11h_data_id_list_s *pkcs11h_data_id_list_t;

/**
 * @brief Data identifier list.
 */
struct pkcs11h_data_id_list_s {
	/** Next element */
	pkcs11h_data_id_list_t next;

	/** Application string */
	char *application;
	/** Label string */
	char *label;
};

/**
 * @brief Get data object.
 * @param token_id		Token id object.
 * @param is_public		Object is public.
 * @param application		Object application attribute.
 * @param label			Object label attribute.
 * @param user_data		Optional user data, to be passed to hooks.
 * @param mask_prompt		Allow prompt.
 * @param blob			Blob, set to NULL to get size.
 * @param p_blob_size		Blob size.
 * @return CK_RV.
 * @note blob may be NULL to get size.
 */
CK_RV
pkcs11h_data_get (
	IN const pkcs11h_token_id_t token_id,
	IN const PKCS11H_BOOL is_public,
	IN const char * const application,
	IN const char * const label,
	IN void * const user_data,
	IN const unsigned mask_prompt,
	OUT unsigned char * const blob,
	IN OUT size_t * const p_blob_size
);

/**
 * @brief Put data object.
 * @param token_id		Token id object.
 * @param is_public		Object is public.
 * @param application		Object application attribute.
 * @param label			Object label attribute.
 * @param user_data		Optional user data, to be passed to hooks.
 * @param mask_prompt		Allow prompt.
 * @param blob			Blob, set to NULL to get size.
 * @param blob_size		Blob size.
 * @return CK_RV.
 */
CK_RV
pkcs11h_data_put (
	IN const pkcs11h_token_id_t token_id,
	IN const PKCS11H_BOOL is_public,
	IN const char * const application,
	IN const char * const label,
	IN void * const user_data,
	IN const unsigned mask_prompt,
	OUT unsigned char * const blob,
	IN const size_t blob_size
);

/**
 * @brief Delete data object.
 * @param token_id		Token id object.
 * @param is_public		Object is public.
 * @param application		Object application attribute.
 * @param label			Object label attribute.
 * @param user_data		Optional user data, to be passed to hooks.
 * @param mask_prompt		Allow prompt.
 * @return CK_RV.
 */
CK_RV
pkcs11h_data_del (
	IN const pkcs11h_token_id_t token_id,
	IN const PKCS11H_BOOL is_public,
	IN const char * const application,
	IN const char * const label,
	IN void * const user_data,
	IN const unsigned mask_prompt
);

/**
 * @brief Free data object list.
 * @param data_id_list		List to free.
 * @return CK_RV.
 */
CK_RV
pkcs11h_data_freeDataIdList (
	IN const pkcs11h_data_id_list_t data_id_list
);

/**
 * @brief Get list of data objects.
 * @param token_id		Token id object.
 * @param is_public		Get a list of public objects.
 * @param user_data		Optional user data, to be passed to hooks.
 * @param mask_prompt		Allow prompt.
 * @param p_data_id_list	List location.
 * @see pkcs11h_data_freeDataIdList().
 * @return CK_RV.
 */
CK_RV
pkcs11h_data_enumDataObjects (
	IN const pkcs11h_token_id_t token_id,
	IN const PKCS11H_BOOL is_public,
	IN void * const user_data,
	IN const unsigned mask_prompt,
	OUT pkcs11h_data_id_list_t * const p_data_id_list
);

#ifdef __cplusplus
}
#endif

#endif				/* __PKCS11H_DATA_H */