// $URL$
// $Id$

#include <CGAL/basic.h>

#if defined(CGAL_USE_GMP) && defined(CGAL_USE_MPFI) && defined(CGAL_USE_RS)

#include <CGAL/Algebraic_kernel_rs_gmpz_1.h>
#include <vector>

typedef CGAL::Algebraic_kernel_rs_gmpz_1                AK;
typedef AK::Polynomial_1                                Polynomial_1;
typedef AK::Algebraic_real_1                            Algebraic_real_1;
typedef AK::Coefficient                                 Coefficient;
typedef AK::Bound                                       Bound;
typedef AK::Multiplicity_type                           Multiplicity_type;

int main(){
  AK ak; // an object of Algebraic_kernel_d_1_RS_Gmpz
  AK::Construct_algebraic_real_1 construct_algreal_1 = ak.construct_algebraic_real_1_object();

  std::cout << "Construct from int         : " << construct_algreal_1(int(2)) << "\n";
  std::cout << "Construct from Coefficient : " << construct_algreal_1(Coefficient(2)) << "\n";
  std::cout << "Construct from Bound       : " << construct_algreal_1(Bound(2)) << "\n\n";

  Polynomial_1 x = CGAL::shift(AK::Polynomial_1(1),1); // the monomial x
  std::cout << "Construct by index              : "
            << construct_algreal_1(x*x-2,1) << "\n"
            << to_double(construct_algreal_1(x*x-2,1)) << "\n";
  std::cout << "Construct by isolating interval : "
            << construct_algreal_1(x*x-2,Bound(0),Bound(2)) << "\n"
            << to_double(construct_algreal_1(x*x-2,Bound(0),Bound(2))) << "\n\n";

  return 0;
}
#else
int main(){
        return 0;
}
#endif
