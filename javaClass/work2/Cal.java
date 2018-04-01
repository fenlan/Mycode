import java.lang.Process;
import java.lang.Runtime;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.InterruptedException;

class Cal {
	static final String[] MONTHS = { 
		"January",  "February",		"March",
		"April",	"May",			"June",
		"July",		"August",		"September",
		"October",	"November",		"December"
	};

	public static void main(String[] args) throws IOException, InterruptedException {
		String[] cmds = new String[3];
		cmds[0] = "/bin/sh";
		cmds[1] = "-c";
		
		if (args.length == 2) {
			int month = Integer.parseInt(args[0]);
			int year = Integer.parseInt(args[1]);
			cmds[2] = "cal " + month + " " + year + " | tail -n 6";
		}
		else {
			cmds[2] = "cal | tail -n 6";  
		}

        Process pro = Runtime.getRuntime().exec(cmds);  
        pro.waitFor();  
        InputStream in = pro.getInputStream();  
        BufferedReader read = new BufferedReader(new InputStreamReader(in));  
        String line = null;  

        System.out.println(MONTHS[3] + " 2025");
        System.out.println("Su Mo Tu We Th Fr Sa");

        while((line = read.readLine())!=null){  
            System.out.println(line);  
        }
	}
}