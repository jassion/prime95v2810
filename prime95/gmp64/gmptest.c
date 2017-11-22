/*gmp-6.0.0.dll 调用测试*/
        #include <stdio.h>
        #include "gmp.h"
        
        #pragma  comment(lib,"libgmp-10.lib")
             int main (void)
           { FILE *f=fopen("a.txt","w");
              int num=50,i;
           
           mpz_t n,m,c,r;
           //char qq[100]; //或用malloc分配空间，并初始化为0
           mpf_t pi,e,xx,yy;//**********
           mpq_t x,y,z;
           printf("gmp_version=%s\n",gmp_version);
           //for(i=0;i<100;i++)
          //qq[i]='\0';
           mpz_init_set_str (n, "13703703579", 10);
           mpz_init_set_str (m, "29012345415", 10);          
           mpz_inits(c,r,'\0');
           mpz_gcd(c,n,m);
           mpz_fac_ui(r,num);             
   
           gmp_printf ("gcd(%Zd,%Zd) = %Zd\n\n%d! =%Zd:\n in base 36:\t",n,m,c,num,r);

           mpz_out_str(stdout,36,r);
           mpz_out_str(f,36,r);
//*************************** 
        /*
           mpz_get_str(qq,36,r);//The base may vary from 2 to 36
                 printf("%s",qq);//console显示输出
            i=0;
          while(qq[i]!=0)
            fputc(qq[i++],f);//写入文件
        */
//*************************** 
            fclose(f);
            
           mpz_fib_ui(r,num);
           gmp_printf("\n\nthe %dth fibonacci number is:\n %Zd\n",num,r);
           mpz_bin_ui(c,n,num);
           gmp_printf("\nBinomial number C(%Zd,%d) is:\n%Zd\n",n,num,c);
           mpz_pow_ui(c,n,num);
           gmp_printf("\n%Zd^%d =:\n%Zd\n",n,num,c);
           
           mpf_set_default_prec(500);
           
           mpf_init_set_str(pi,"3.14159265358979323846264338327950288419716939937510582097494459230781",10);
           mpf_init_set_str(e ,"2.71828182845904523536028747135266249775724709369995957496696762772407",10);
           mpf_inits(xx,yy,'\0');
           mpf_pow_ui(xx,pi,4);mpf_pow_ui(yy,pi,5);
           mpf_add(xx,xx,yy);
           mpf_pow_ui(yy,e,6);
           gmp_printf("\npi^4+pi^5=%.50Ff\ne^6\t =%.50Ff\n\ninput a number to compute its next prime,",xx,yy);
           gmp_printf("arbitraryly large:\n");
           gmp_scanf("%Zd",c);
           mpz_nextprime(r,c);
           gmp_printf("after %Zd,closely followed a prime:\n%Zd\n\n",c,r);
                         
          
           mpq_inits(x,y,z,'\0');
           gmp_printf("you input two fractions with a plus sign(2/4+1/3),I compute their sum:\n");
           gmp_scanf ("%Qd + %Qd",x,y);
           mpq_canonicalize(x);
           mpq_canonicalize(y);
           mpq_add(z,x,y);
           gmp_printf("\nactually,after reduction,your equation is:\n%Qd+%Qd = %Qd\nGoodbye!\n",x,y,z);
             
           mpz_clears(m,n,c,r,'\0');
           mpq_clears(x,y,z,'\0');
           mpf_clears(xx,yy,'\0'); 

       return 0;
     }