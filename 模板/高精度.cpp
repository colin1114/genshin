struct opera
{
    ll a[105];
    opera() 
	{
        fill(a, a + 105, 0);
    }
    opera(ll s)
    {
        fill(a, a + 105, 0);
        while (s)
        {
            a[++a[0]] = s % 10;
            s /= 10;
        }
    }
    opera operator + (const opera &s) const
	{
        opera c;
        c.a[0] = max(a[0], s.a[0]);
        for (int i = 1; i <= c.a[0]; i++) 
		{
            c.a[i] += a[i] + s.a[i];
            c.a[i + 1] += c.a[i] / 10, c.a[i] %= 10;
        }
        if (c.a[c.a[0]]) 
			c.a[0]++;
        return c;
    }
    opera operator * (const opera &s) const
	{
        opera c;
        c.a[0] = a[0] + s.a[0] - 1;
        for (int i = 1; i <= a[0]; i++) 
			for (int j = 1; j <= s.a[0]; j++) 
			{
	            ll x = i + j - 1;
	            c.a[x] += a[i] * s.a[j];
	            c.a[x + 1] += c.a[x] / 10;
	            c.a[x] -= (c.a[x] / 10) * 10;
	        }
        while (c.a[c.a[0] + 1]) 
			c.a[++c.a[0] + 1] += c.a[c.a[0]] / 10, c.a[c.a[0]] %= 10;
        return c;
    }
    bool operator > (const opera &s) const
	{
        if (a[0] > s.a[0])
			return 1;
        if (a[0] < s.a[0]) 
			return 0;
        for (int i = a[0]; i >= 1; i--) 
		{
            if (a[i] > s.a[i]) 
				return 1;
            if (a[i] < s.a[i]) 
				return 0;
        }
        return 0;
    }
    void print() 
	{
        for (int i = a[0]; i >= 1; i--) 
			cout << a[i];
        cout << endl;
    }
};