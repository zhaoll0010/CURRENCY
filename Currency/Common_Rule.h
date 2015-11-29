#ifndef _INCL_COMMON_RULE
#define _INCL_COMMON_RULE
#include <cstdint>
class Common_Rule
{
public:
	uint8_t gen1[2];
	uint8_t gen2[3];
	uint8_t gen3[1];

	static const int GEN_LEN1 = 5;
	static const int GEN_LEN2 = 1;
	static const int GEN_LEN3 = 2;

	static const int NUMBER1 = 2;
	static const int NUMBER2 = 3;
	static const int NUMBER3 = 1;
	static const int NUMBER = NUMBER1 + NUMBER2 + NUMBER3;
	static const int LENGTH1 = GEN_LEN1 * NUMBER1;
	static const int LENGTH2 = GEN_LEN2 * NUMBER2;
	static const int LENGTH3 = GEN_LEN3 * NUMBER3;
	static const int LENGTH = LENGTH1 + LENGTH2 + LENGTH3;

	Common_Rule();
	void operator=(Common_Rule &r);
};
#endif