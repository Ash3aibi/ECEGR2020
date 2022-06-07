N = input("Enter any Even Number Between 100 and 200:");
sum = 0;
for i=1:N
    sum = sum + (i / (3 .^ (2 * i + 1))) + (i / (3 .^ (2 * i + 2)));
end

fprintf("The Sum is: %f\n", sum);