/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-PDU-Contents"
 * 	found in "./asn1c/S1AP-PDU-Contents.asn"
 * 	`asn1c -fcompound-names -fno-include-deps -gen-PER -findirect-choice -pdu=S1AP-PDU`
 */

#ifndef	_E_RABSetupListCtxtSURes_H_
#define	_E_RABSetupListCtxtSURes_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolIE_SingleContainer;

/* E-RABSetupListCtxtSURes */
typedef struct E_RABSetupListCtxtSURes {
	A_SEQUENCE_OF(struct ProtocolIE_SingleContainer) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E_RABSetupListCtxtSURes_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E_RABSetupListCtxtSURes;
extern asn_SET_OF_specifics_t asn_SPC_E_RABSetupListCtxtSURes_specs_1;
extern asn_TYPE_member_t asn_MBR_E_RABSetupListCtxtSURes_1[1];
extern asn_per_constraints_t asn_PER_type_E_RABSetupListCtxtSURes_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _E_RABSetupListCtxtSURes_H_ */
#include <asn_internal.h>
