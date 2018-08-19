public class MyCalendar {
	private Node first;

	class Node {
		private int start;
		private int end;
		private Node pre;
		private Node next;

		public Node(int start, int end, Node pre, Node next) {
			this.start = start;
			this.end = end;
			this.pre = pre;
			this.next = next;
		}
	}

	public MyCalendar() { first = null; }

	private boolean book(int start, int end) {
		if (start > end) {
			return false;
		}
		else if (first == null) {
			first = new Node(start, end, null, null);
			return true;
		}
		else if (start < first.start) {
			if (end <= first.start) {
				Node nNode = new Node(start, end, null, first);
				first.pre = nNode;
				first = nNode;
				return true;
			} else {
				return false;
			}
		}
		else {
			Node tmp = first;
			while (tmp != null) {
				if (start >= tmp.end && tmp.next != null) {
					tmp = tmp.next;
				}
				else if (start >= tmp.end) {
					Node nNode = new Node(start, end, tmp, null);
					tmp.next = nNode;
					return true;
				}
				else if (end <= tmp.start) {
					Node nNode = new Node(start, end, tmp.pre, tmp);
					tmp.pre.next = nNode;
					tmp.pre = nNode;
					return true;
				}
				else
					return false;
			}
			return false;
		}
	}

	public static void main(String[] args) {
		MyCalendar cal = new MyCalendar();
		System.out.println(cal.book(10, 20));
		System.out.println(cal.book(15, 25));
		System.out.println(cal.book(20, 30));
		System.out.println(cal.book(0, 10));
		System.out.println(cal.book(50, 60));
		System.out.println(cal.book(45, 55));
		System.out.println(cal.book(55, 60));
		System.out.println(cal.book(35, 50));
		System.out.println(cal.book(30, 35));
		System.out.println(cal.book(15, 25));
	}
}