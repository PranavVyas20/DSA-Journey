import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int[] n =
        {
            Integer.parseInt(st.nextToken()),
            Integer.parseInt(st.nextToken()),
            Integer.parseInt(st.nextToken())
        };

        int[][] h = new int[3][];
        int[] sum = new int[3];
        for(int i=0;i<3;i++)
        {
            st = new StringTokenizer(in.readLine());
            h[i] = new int[n[i]];
            for(int j=0;j<n[i];j++)
            {
                h[i][j] = Integer.parseInt(st.nextToken());
                sum[i] += h[i][j];
            }
        }

        int[] pos = new int[3];
        while(true)
        {
            for(int i=0;i<3;i++)
                if(sum[i] > Math.min(sum[0], Math.min(sum[1], sum[2])))
                {
                    sum[i] -= h[i][pos[i]];
                    pos[i]++;
                }
            if(sum[0] == sum[1] && sum[1] == sum[2])
                break;
        }

        System.out.println(sum[0]);
    }
}