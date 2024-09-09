#include "iter.hpp"

int main()
{
	char c[] = { 'a', 'b', 'c' };

	::iter(c, 3, ::magic);

	return 0;
}