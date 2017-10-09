double f(double res)
{
	return res*res*res*res * 8 + res*res*res * 7 + res*res * 2 + res * 3 + 6;
}



while (fabs(f(tem) - y) >= 1e-5)//y为给出的y值,b和e的初始值为给出的根的范围
				if (f(tem)>y){
					e = tem;
					tem = (b + e) / 2;
				}
				else{
					b = tem;
					tem = (b + e) / 2;
				}
