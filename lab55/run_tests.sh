./build/program args output.txt
sort -o output.txt output.txt
sort -o expected_output.txt expected_output.txt

echo "Tests"

if cmp -s "expected_output.txt" "output.txt"; then
    echo "Passed"
else
    echo "Fail"
fi
rm output.txt
