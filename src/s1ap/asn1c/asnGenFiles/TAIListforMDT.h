/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./asn1c/S1AP-IEs.asn"
 * 	`asn1c -fcompound-names -fno-include-deps -gen-PER -findirect-choice -pdu=S1AP-PDU`
 */

#ifndef	_TAIListforMDT_H_
#define	_TAIListforMDT_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct S_TAI;

/* TAIListforMDT */
typedef struct TAIListforMDT {
	A_SEQUENCE_OF(struct S_TAI) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TAIListforMDT_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TAIListforMDT;
extern asn_SET_OF_specifics_t asn_SPC_TAIListforMDT_specs_1;
extern asn_TYPE_member_t asn_MBR_TAIListforMDT_1[1];
extern asn_per_constraints_t asn_PER_type_TAIListforMDT_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _TAIListforMDT_H_ */
#include <asn_internal.h>
