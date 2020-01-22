#!/bin/bash

solution=false
for (( x = 1; x <= $1; ++x ))
do
   for (( y = 1; y <= $2; ++y ))
   do
      for (( z = 1; z <= $3; ++z ))
      do
         for (( w = 1; w <= $4; ++w ))
         do

            a=$(( (x*x*x)+(y*y*y) ))
            b=$(( (z*z*z)+(w*w*w) ))
            
            if [ $a -eq $b ]
            then 
               solution=true
               echo x= $x, y= $y, z= $z, w= $w 
            fi

         done
      done
   done
done

if [ $solution = false ]
then 
   echo No solution
fi