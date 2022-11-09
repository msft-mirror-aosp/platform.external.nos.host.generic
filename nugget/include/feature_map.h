/**
 * \file
 * Feature ID format and inline decode functions
 */

#pragma once

#ifndef __ASSEMBLER__

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
	km_feature_max = FEATURE_MASK, // For 24-bit alignment
};

/*****************************************************************************/

/**
 * Query the feature supporting status based on task_id and module_id.
 *
 * @param id: APP_ID which is define in enum feature_support_app_id{}
 * @param module_id: sub module list defined above
 * @param is_supported: to output the supporting status. True = support.
 *
 * @return ERR_NONE, or error
 *
 * NOTE: "id" here is different from the TASK_ID_xxx (which is mutable) or
 *       APP_ID_xxx (which is out of hex range).
 *       Instead, we define a fixed order list which can be shared external.
 * */
__err_t is_feature_supported_by_task(enum feature_support_app_id id,
				     uint32_t module_id, bool *is_supported);
#endif /* !__ASSEMBLER__ */
