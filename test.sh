#!/bin/bash


while true; do
  
  # Prompt the user for the operation name or termination command
  read -p "op: " input
  
  # end server
  if [ "$input" = "exit" ]; then
    echo "end mysql server..."
    sudo systemctl stop mysql
    break  # Exit the loops
  fi
  
  # Use a case statement to handle different input variations
  case "$input" in
    
    start)
      echo "start mysql server..."
      sudo systemctl start mysql 
      ;;
    
    end)
      echo "end mysql server..."
      sudo systemctl stop mysql
      ;;
      
    status)
      sudo systemctl status mysql
      ;;
      
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
      echo "Invalid input. Please enter : (start | end | run | commit | push )"
      ;;
      
  esac
done

#server




#compilation



#run



#push to origin


