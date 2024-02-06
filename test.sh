#!/bin/bash

while true; do
  
  # Prompt the user for the operation name or termination command
  read -p "Enter operation name (start | end | run | commit | push ): " input
  
  # start command 'start'
  if [ "$input" = "start" ]; then
    echo "start mysql server..."
    sudo systemctl start mysql
    break
  fi
  
  # termination command 'exit'
  if [ "$input" = "end" ]; then
    echo "end mysql server..."
    sudo systemctl stop mysql
    break  # Exit the loops
  fi
  
  # Use a case statement to handle different input variations
  case "$input" in
    run)
      echo "run"
      g++ -o test test.cpp -lmysqlcppconn
      ./test      
      ;;
    commit)
      git add .
      
      read -p "commit message: " commit_message
      git commit -m "$commit_message"
      
      echo "commit -m '$commit_message' ..."
      ;;
    push)
      echo "push"
      git push origin master
      ;;
    *)
      echo "Invalid input. Please enter 'A' or 'B'."
      ;;
  esac
done

#server




#compilation



#run



#push to origin


