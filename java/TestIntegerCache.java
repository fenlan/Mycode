/* ------------------------------------------
 * 	Author: fenlan
 * 	Date: 2017.7.22
 * ------------------------------------------
 * 	Output:
 *		true
 * 		false
 * ------------------------------------------
 * 	Integer 的作者在写这个类时，为了避免重复创建对象，
 * 对Integer 值做了缓存，如果这个值在缓存范围内，直接
 * 返回缓存好的对象，否则new一个新的对象返回。
 * ------------------------------------------
 */

public class TestIntegerCache {
	public static void main(String[] args) {
		Integer i3 = 100;
		Integer i4 = 100;
		System.out.println(i3 == i4);

		Integer i5 = 1000;
		Integer i6 = 1000;
		System.out.println(i5 == i6);
	}
}
