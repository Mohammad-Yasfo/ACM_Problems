template <class T> string number_to_string (T Number){
	string String = static_cast<ostringstream*>( &(ostringstream() << Number) )->str();
	return String;
}
 template <typename T>
  T StringToNumber ( const string &Text )
  {
     istringstream ss(Text);
     T result;
     return ss >> result ? result : 0;
  }
