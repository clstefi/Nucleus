/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./asn1c/S1AP-IEs.asn"
 * 	`asn1c -fcompound-names -fno-include-deps -gen-PER -findirect-choice -pdu=S1AP-PDU`
 */

#ifndef	_RecommendedENBsForPaging_H_
#define	_RecommendedENBsForPaging_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RecommendedENBList.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* RecommendedENBsForPaging */
typedef struct RecommendedENBsForPaging {
	RecommendedENBList_t	 recommendedENBList;
	struct ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RecommendedENBsForPaging_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RecommendedENBsForPaging;
extern asn_SEQUENCE_specifics_t asn_SPC_RecommendedENBsForPaging_specs_1;
extern asn_TYPE_member_t asn_MBR_RecommendedENBsForPaging_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _RecommendedENBsForPaging_H_ */
#include <asn_internal.h>
