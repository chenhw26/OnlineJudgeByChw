import java.util.Scanner;
import static java.lang.System.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(in);
		String num = scan.next();
		while(!num.equals("0")){
			int sum = 0;
			for(int i = 0; i < num.length(); ++i){
				sum += (int)num.codePointAt(i) - (int)'0';
				if(sum > 9) sum = sum / 10 + sum % 10;
			}
			out.printf("%d\n", sum);
			num = scan.next();
		}
		scan.close();
	}
}
