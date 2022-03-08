#ifndef ALASEstimativeSort
#define ALASEstimativeSort

namespace alas
{
	template <typename t> void EstimativeSort(t* a, int s)
	{
		if(s-1)
		{
			t m=*a, m2=0;
			for(int i=0; i<s; i++)
			{
				if(a[i]<m)
				m=a[i];
				if(a[i]>m2)
				m2=a[i];
			}
			double e=(m2-m)/(s-1);
			if(!e)
			e=1;
			t* na=new t[s];
			bool* nb=new bool[s];
			for(int i=0; i<s; i++)
			{
				nb[i]=0;
			}
			int w=s-1;
			for(int i=0; i<s; i++)
			{
				int p=(a[i]-m)/e;
				if(p<s)
				{
					if(!nb[p])
					{
						na[p]=a[i];
						nb[p]=1;
					}
					else
					{
						int u=1;
						bool j=0, l=0;
						while(!j)
						{
							if(p+u<s)
							{
								if(!nb[p+u])
								{
									na[p+u]=a[i];
									nb[p+u]=1;
									j=1;
									l=1;
								}
							}
							if(p-u>=0 && !l)
							if(!nb[p-u])
							{
								na[p-u]=a[i];
								nb[p-u]=1;
								j=1;
							}
							u++;
						}
					}
				}
				else
				{
					while(nb[w])
					{
						w--;
					}
					na[w]=a[i];
					nb[w]=1;
					w--;
				}
			}
			for(int i=0; i<s; i++)
			{
				a[i]=na[i];
			}
			delete[] na;
			delete[] nb;
			bool done=0;
			while(!done)
			{
				done=1;
				for(int i=s-1; i>0; i--)
				{
					if(a[i]<a[i-1])
					{
						t uff=a[i];
						a[i]=a[i-1];
						a[i-1]=uff;
						done=0;
					}
				}
			}
		}
	}
}

#endif
