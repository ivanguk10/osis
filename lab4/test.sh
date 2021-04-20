test=(test/test*.txt)

for i in "${!test[@]}";do
	echo "Here we go test $((i+1))"
	./build/program<"${test[$i]}" >"test/output$((i+1)).txt"
	if cmp -s "test/output$((i+1)).txt" "test/result$((i+1)).txt";then
		echo "Passed"
	else
		echo "Fail"
		break
	rm ./test/"output$((i+1)).txt"
	fi
done
