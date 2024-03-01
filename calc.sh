echo -e "Enter choice 1.addition\n2.Subtraction\n3.Multiplication\n4.Division"
read choice
echo "enter two Numbers   :"
read num1
read num2

case $choice in
    1) 
         echo "Sum of $num1 and $num2 :"$((num1+num2));;
 
    2)  
         echo "Difference of $num1 and $num2 :$(($num1-$num2))";;

    3)
          echo "Product of $num1 and $num2 :$(($num1*$num2))";;
    
    4)
          echo "$num1/$num2 is   :$((num1/num2))";;
    
    *)
           echo "Wrong Choice";;
         esac
