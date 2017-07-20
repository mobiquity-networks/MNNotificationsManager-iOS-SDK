Pod::Spec.new do |s|
  s.name                = "MNNotifications"
  s.version             = "2.5.1"
  s.summary             = "SDK to interact with Beacons and Geofences using the Mobiquity Networks Server platform"
  s.homepage            = "http://www.mobiquitynetworks.com"
  s.license             = "Copyright © 2016 by Mobiquity Networks, Inc. All rights reserved."
  s.author              = { "Steve Reeves" => "steve@distillmobile.com" }
  s.platform            = :ios, "8.0"

  s.source              = { :git => "https://github.com/mobiquity-networks/MNNotificationsManager-iOS-SDK", :tag => s.version.to_s }
  s.vendored_frameworks =  "MNNotifications.framework"
   
  s.requires_arc        = true
end
