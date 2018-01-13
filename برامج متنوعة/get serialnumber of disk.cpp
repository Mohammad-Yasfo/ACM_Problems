string drive = "C";
ManagementObject disk = new ManagementObject("win32_logicaldisk.deviceid=\"" + drive + ":\"");
disk.Get();
textBox1.Text = "VolumeSerialNumber=" + disk["VolumeSerialNumber"].ToString();