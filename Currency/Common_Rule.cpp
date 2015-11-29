#include "Common_Rule.h"

Common_Rule::Common_Rule() {}
void Common_Rule::operator=(Common_Rule &r)
{
	for (int i = 0; i < NUMBER1; i++)
	{
		gen1[i] = r.gen1[i];
	}
	for (int i = 0; i < NUMBER2; i++)
	{
		gen2[i] = r.gen2[i];
	}
	for (int i = 0; i < NUMBER3; i++)
	{
		gen3[i] = r.gen3[i];
	}
}
