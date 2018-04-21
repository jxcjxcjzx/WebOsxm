// this interface is served as the main drawing function
interface draw_in_main
{
  void draw_things();
}

// this is for the system_function use
interface system_functions
{
  boolean checklink();
  void initial();
  boolean check_length(ArrayList<String> for_check,int require);
}

// this is for the system signals necessary when running the system
interface sys_signals
{
  void reset();
  void set_boolean_signal(String info,boolean whethertrue);
  void set_int_signal(String info,int value);  
  boolean sendout_boolean_signal(String command);
  int sendout_int_signal(String command);  
}

// this is for the reminders and helpers when trouble comes to users
interface sys_reminders
{
  void reset();
  void draw_bar();
  void clear_bar();
  void set_reminder(String info);
}

interface commander
{
  void handle_command();
  void show_command();
  String get_handle_result();
  void get_command();
}

