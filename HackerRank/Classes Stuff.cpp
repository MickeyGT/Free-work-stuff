		try
		{
			Server y;
			long long x=y.compute(A, B);
			cout << x << '\n';
		}
		catch (bad_alloc&)
		{
			cout << "Not enough memory\n";
		}
		catch (exception &e)
		{
			cout << "Exception: " << e.what() << endl;
		}
		catch (...)
		{
			cout << "Other Exception" << endl;
		}
    
    ///////////////////////////////////////////////
    
    	friend ostream& operator <<(ostream& out,const Box& B)
	{
		out << B.l<<' '<<B.b<<' '<<B.h;
		return out;
	}
  
  /////////////////////////////////////////////////
