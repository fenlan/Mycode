class SubString {
	public static void main(String[] args) {
		if (args.length == 3) {
			String str = args[0];
			int start = Integer.parseInt(args[1]);
			int num = Integer.parseInt(args[2]);

			for (int i = start; i < start+num; i++) {
				if (i < str.length()) {
					System.out.print(str.charAt(i));
				}
			}
			System.out.println();
		}
		else {
			System.out.println("args length is not right!");
		}
	}
	
}