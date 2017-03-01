
#ifndef GENL_TEST_H
#define GENL_TEST_H

#include <linux/netlink.h>

#ifndef __KERNEL__
#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>
#endif

#define GENL_TEST_FAMILY_NAME		"genl_test"
#define GENL_TEST_MCGRP0_NAME		"genl_mcgrp0"
#define GENL_TEST_MCGRP1_NAME		"genl_mcgrp1"
#define GENL_TEST_MCGRP2_NAME		"genl_mcgrp2"

#define GENL_TEST_ATTR_MSG_MAX		256
#define GENL_TEST_HELLO_INTERVAL	5000

enum {
	GENL_TEST_C_UNSPEC,		/* Must NOT use element 0 */
	GENL_TEST_C_MSG,
};

enum genl_test_multicast_groups {
	GENL_TEST_MCGRP0,
	GENL_TEST_MCGRP1,
	GENL_TEST_MCGRP2,
};
#define GENL_TEST_MCGRP_MAX		3

static char* genl_test_mcgrp_names[GENL_TEST_MCGRP_MAX] = {
	GENL_TEST_MCGRP0_NAME,
	GENL_TEST_MCGRP1_NAME,
	GENL_TEST_MCGRP2_NAME,
};

enum genl_test_attrs {
	GENL_TEST_ATTR_UNSPEC,		/* Must NOT use element 0 */

	GENL_TEST_ATTR_MSG,

	__GENL_TEST_ATTR__MAX,
};
#define GENL_TEST_ATTR_MAX (__GENL_TEST_ATTR__MAX - 1)

static struct nla_policy genl_test_policy[GENL_TEST_ATTR_MAX+1] = {
	[GENL_TEST_ATTR_MSG] = {
		.type = NLA_STRING,
#ifdef __KERNEL__
		.len = GENL_TEST_ATTR_MSG_MAX
#else
		.maxlen = GENL_TEST_ATTR_MSG_MAX
#endif
	},
};

#endif
