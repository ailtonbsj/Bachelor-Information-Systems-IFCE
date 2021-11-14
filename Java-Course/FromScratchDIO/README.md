# History

```bash
# Create source and package
mkdir -p src/com/dio/

# Create main entrypoint
vim src/com/dio/MyFirstProgram.java

# Create another package
mkdir -p src/com/dio/base/

# Create Order class
vim src/com/dio/base/Order.java

# Compile the project
javac -d target/ -sourcepath src/ src/com/dio/MyFirstProgram.java

# Run the project
cd target/
java com.dio.MyFirstProgram

# Generate documentation
cd ..
javadoc -d javadoc/ -sourcepath src/ -subpackages com.dio
```
