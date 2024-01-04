awk 'BEGIN {ans = 1; printf "LCM("}
    ! /^$/ {while}
    # END {printf "%s", ans}
    ' $1