import java.util.Scanner;
import java.util.Locale;
import java.io.IOException;
import java.io.FileInputStream;

public class Main
{
    public static void main(String[] args) throws IOException
    {
		//FileInputStream fis = new FileInputStream("input");
		//System.setIn(fis);
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner (System.in);
		
		char[] vis = new char[105];
		vis[0] = 1;
		int n, m, i, j, k;
		while ((n = in.nextInt()) != 0)
		{
			for (m = 1; ; ++m)
			{
				for (i = 1; i < n; ++i)
					vis[i] = 0;
				for (i = 0; i != 12; )
				{
					for (j = i, k = 0; k < m; )
						if (vis[j = (j + 1) % n] == 0)
							++k;
					vis[i = j] = 1;
				}
				for (i = 0; i < n && vis[i] != 0; ++i);
				if (i == n)
					break;
			}
			System.out.printf("%d\n", m);
		}
	}
}
