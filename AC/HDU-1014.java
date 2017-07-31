import static java.lang.System.*;
import java.util.*;
public class Main
{
	static Scanner cin = new Scanner(in);
	static Formatter f = new Formatter();
	public static void main(String[] args)
	{
		int s, m, kase;
		while(cin.hasNext()){
			s = cin.nextInt();
			m = cin.nextInt();
			int max = m > s? m: s;
			int min = m + s - max;
			out.printf("%10d%10d    %s", s, m, (gcd(max, min) == 1? "Good Choice": "Bad Choice"));
			out.println(); out.println();
		}
		cin.close();
	}
	
	public static int gcd(int a, int b){
		if(b == 0) return a;
		return gcd(b, a % b);
	}
}
