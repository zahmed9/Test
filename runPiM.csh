#!/bin/csh

set c=1
while ( $c <= 4 )
	<< EOF ./pim 
5
$c
EOF

	@ c = $c + 1
end
