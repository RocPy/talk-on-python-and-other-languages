subroutine del2(stuff, fuzz, m, n)
implicit none

integer, intent(in) :: m
integer, intent(in) :: n
double precision, intent(in), dimension(m,n) :: stuff
double precision, intent(inout), dimension(m,n) :: fuzz

integer :: j
integer :: k

do j = 1, m
    fuzz(j,1) = 0.0
    fuzz(j,n) = 0.0
end do

do k = 1, n
   fuzz(1,k) = 0.0
   fuzz(m,k) = 0.0
end do

do j = 2, m-1
   do k = 2, n-1
      fuzz(j,k) = 0.5*( &
      stuff(j-1,k) +    &
      stuff(j+1,k) +    &
      stuff(j,k-1) +    &
      stuff(j,k+1) -    &
      4.0*stuff(j,k)    &
      )
   end do
end do

end subroutine del2
