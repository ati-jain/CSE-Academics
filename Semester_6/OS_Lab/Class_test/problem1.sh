# Atishay Jain
# 20CS30008
read x
read y
read m
if [[ $x -le 0 ]]; then
	echo invalid input
	exit
fi
if [[ $y -le 0 ]]; then
	echo invalid input
	exit	
fi
y2=$((y**y))
if [[ $m -le 0 ]]; then
	echo invalid input
	exit
fi
# calculating y^2%m
y2_mod_m=$((y2%m))
# calculating x^(y^2%m)
exp_term=$((x**y2_mod_m))
# calculating final answer
ans=$((exp_term%m))
echo $ans
