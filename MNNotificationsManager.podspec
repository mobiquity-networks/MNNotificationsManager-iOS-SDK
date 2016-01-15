Pod::Spec.new do |s|
  s.name             = "MNNotificationsManager"
  s.version          = "1.1.1"
  s.summary          = "SDK to interact with Beacons and Geofences using the Mobiquity Networks Server platform"
  s.homepage         = "http://www.mobiquitynetworks.com"
  s.license          = 'Copyright © 2016 by Mobiquity Networks, Inc. All rights reserved.'
  s.author           = { "Alberto Salas" => "albsala.work@gmail.com" }
  s.source           = { :git => "https://github.com/mobiquity-networks/MNNotificationsManager-iOS-SDK", :tag => s.version.to_s }

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.resources = 'MNProximityManager.bundle'
  s.vendored_frameworks = 'MNNotificationsManager.framework'
  
  s.frameworks = 'CoreLocation', 'CoreData', 'MobileCoreServices', 'AdSupport', 'CoreBluetooth', 'UIKit', 'CoreTelephony'
end