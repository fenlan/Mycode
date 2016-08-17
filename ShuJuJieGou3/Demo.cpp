# include "CMap.h"
# include "Node.h"
# include <iostream>
# include <stdlib.h>
using namespace std;

/*       A
 *     /   \
 *    B     D
 *   / \   / \
 *  C   F G - H
 *   \ /
 *    E
 */

/*    A B C D E F G H
 * A    1   1
 * B  1   1     1
 * C    1     1 1
 * D  1           1 1
 * E      1
 * F    1 1
 * G        1       1
 * H        1     1
 */

int main(void)
{
	CMap * pMap = new CMap(8);

	system("pause");
	return 0;
}
