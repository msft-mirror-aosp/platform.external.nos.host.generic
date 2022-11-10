/**
 * \file
 * Feature ID format and inline decode functions
 */

#pragma once

/*****************************************************************************/

#define TA_MASK 0xFF000000
#define TA_OFFSET 24
#define TA_FIELD 8 // Max 256 TAs

#define FEATURE_MASK 0x00FFFFFF
#define FEATURE_OFFSET 0
#define FEATURE_FIELD 24 // Can support up to 2^24 features

#define TA_FROM_FEATURE_ID(id)                                                 \
	((enum feature_support_app_id)((id & TA_MASK) >> TA_OFFSET))
#define MODULE_FROM_FEATURE_ID(id) ((id & FEATURE_MASK) >> FEATURE_OFFSET)
/*****************************************************************************/

enum feature_support_app_id {
	feature_id_avb = 0,
	feature_id_gfa,
	feature_id_identity,
	feature_id_keymint,
	feature_id_nugget,
	feature_id_weaver,
	feature_id_count,
	feature_id_max = 0xff, // For 8-bit alignment
};

enum km_feature_list {
	km_feature_individual_attest,
	km_feature_batch_attest,
	km_feature_gnubby_attest,
	km_feature_rkp,
	km_feature_rkp_dice,
	km_feature_dice,
	km_feature_max = FEATURE_MASK,  // For 24-bit alignment
};
