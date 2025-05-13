#!/usr/bin/env bash
# Generate a 20 character random password
# Explanation:
# 	<: An input redirection operator that passes the contents of the 
#       following file as input to the command.
#	/dev/urandom: A special file that generates a stream of pseudo-random
#	bytes.
#	tr: A command that translates or deletes characters.
#	-dc: Options for tr where -d means delete and -c means complement;
#	together, they delete all characters not in the given set.
#	head -c20: A command that outputs the first 12 characters (or bytes)
#	from its input. 

PASSWORD=$(< /dev/urandom tr -dc 'A-Za-z0-9_@#%*+' | head -c20)
echo "Your new password is: $PASSWORD"
