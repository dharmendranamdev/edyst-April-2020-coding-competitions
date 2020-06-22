import java.util.*;
class Main
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0)
        {
            t--;
            int n=sc.nextInt();
            String[] a=new String[n];
            long res=0;
            sc.nextLine();
            int[] v=new int[n+1];
            long[] r=new long[n+1];
            HashMap<Integer,ArrayList<Integer>> hm=new HashMap<>();
            for(int i=0;i<n;i++)
            {
                a[i]=sc.nextLine();
                //System.out.println(a[i]);
                String[] s=a[i].split(" ");
                v[Integer.parseInt(s[0])]=Integer.parseInt(s[1]);
                ArrayList<Integer> list=new ArrayList<>();
                for(int j=2;j<s.length;j++)
                {
                    if(Integer.parseInt(s[j])!=0)
                        list.add(Integer.parseInt(s[j]));
                }
                hm.put(Integer.parseInt(s[0]),list);
            }
            for(int i=1;i<n;i++)
                if(r[i]==0)
                    r[1]=find(i,v,r,hm,n);
            for(int i=1;i<=n;i++)
            {
                res=Math.max(res,r[i]);
            }
            System.out.println(res);
        }
    }
    public static long find(int i,int[] v,long[] r,HashMap<Integer,ArrayList<Integer>> hm,int n)
    {
        if(r[i]!=0)
        {
            //System.out.println(r[i]);
            return r[i];
        }
        ArrayList<Integer> list=hm.get(i);
        long ret=v[i];
        long max=0;
        for(int j: list)
        {
            long temp=find(j,v,r,hm,n);
            if(temp>max)
                max=temp;
        }
        r[i]=ret+max;
        return r[i];
    }
}